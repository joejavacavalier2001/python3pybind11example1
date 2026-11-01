#!/usr/bin/python3
import tree_shared_module
import gc

def test_shared_ptr_lifecycle():
    print("--- 1. Creating Nodes in Python ---")
    my_tree = tree_shared_module.Tree()
    root_node = tree_shared_module.Node("Root")
    left_child = tree_shared_module.Node("Left_Child")
    right_child = tree_shared_module.Node("Right_Child")

    print("\n--- 2. Building Structure (Sharing Ownership) ---")
    root_node.left = left_child
    root_node.right = right_child
    my_tree.set_root(root_node)

    print("\n--- 3. Traversal ---")
    print(f"In-order: {my_tree.traverse_inorder()}")
    
    print("\n--- 4. Dropping Local References to Children ---")
    # Even if Python loses track of children variables, C++ keeps them alive 
    # because 'root_node' holds a shared_ptr reference to them.
    left_child = None
    right_child = None
    print("Children variables set to None. (Notice no destructors fired yet)")

    print("\n--- 5. Exiting function scope ---")

test_shared_ptr_lifecycle()

# Force garbage collection to instantly visualize the destructor execution
gc.collect()
print("\n--- 6. Python script completed ---")

