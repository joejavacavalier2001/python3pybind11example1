#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <iostream>
#include <vector>
#include <string>
#include <memory>

namespace py = pybind11;

// -------------------------------------------------------------------------
// CLASS 1: Node
// -------------------------------------------------------------------------
class Node {
public:
    std::string name;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(const std::string& name) : name(name), left(nullptr), right(nullptr) {
        std::cout << "[C++] Node '" << name << "' created.\n";
    }

    ~Node() {
        std::cout << "[C++] Node '" << name << "' destroyed.\n";
        // No manual deletes needed! Smart pointers automatically clean up children.
    }
};

// -------------------------------------------------------------------------
// CLASS 2: Tree
// -------------------------------------------------------------------------
class Tree {
private:
    std::shared_ptr<Node> root;

    void inorder_helper(std::shared_ptr<Node> current, std::vector<std::string>& result) {
        if (!current) return;
        inorder_helper(current->left, result);
        result.push_back(current->name);
        inorder_helper(current->right, result);
    }

public:
    Tree() : root(nullptr) {
        std::cout << "[C++] Tree container initialized.\n";
    }

    ~Tree() {
        std::cout << "[C++] Tree container destroyed.\n";
        // Automatically releases root reference count
    }

    void set_root(std::shared_ptr<Node> n) { 
        root = n; 
    }
    
    std::shared_ptr<Node> get_root() const { 
        return root; 
    }

    std::vector<std::string> traverse_inorder() {
        std::vector<std::string> result;
        inorder_helper(root, result);
        return result;
    }
};

// -------------------------------------------------------------------------
// PYBIND11 MODULE DEFINITION
// -------------------------------------------------------------------------
PYBIND11_MODULE(tree_shared_module, m) {
    m.doc() = "pybind11 tree structure using std::shared_ptr";

    // Register Node with std::shared_ptr holder type
    py::class_<Node, std::shared_ptr<Node>>(m, "Node")
        .def(py::init<const std::string&>())
        .def_readwrite("name", &Node::name)
        .def_readwrite("left", &Node::left)
        .def_readwrite("right", &Node::right);

    // Register Tree with std::shared_ptr holder type
    py::class_<Tree, std::shared_ptr<Tree>>(m, "Tree")
        .def(py::init<>())
        .def("set_root", &Tree::set_root)
        .def("get_root", &Tree::get_root)
        .def("traverse_inorder", &Tree::traverse_inorder);
}

