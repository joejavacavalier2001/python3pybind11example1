This is a quick example of calling C++ shared libraries from Python3
Here are a few assumptions:
1. python3 is installed and available at /usr/bin/python3
2. pybind11 is installed
3. cmake and g++ is installed and kept updated
4. You download these files in a sub-directory where you are allowed to make temporary files and sub-directories

You should give "run_cmake.sh" and "run_shared.py" execute file permissions.
In the bash shell prompt, cd into the directory containing all of these files and run "./run_cmake.sh"
In the bash shell prompt, run "./run_shared.py"git init
