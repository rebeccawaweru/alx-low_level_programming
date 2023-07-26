Make is a build automation tool used primarily in Unix-based systems to manage the compilation and building of software projects. It reads a file called Makefile to determine how to build and compile the project.
A Makefile: contains rules and instructions on how to compile the source files and create the final executable or library.
Makefiles are used when you have a project with multiple source files and dependencies, and you want an automated way to compile and build the project.
Explicit Rules: These are rules that explicitly define how to build a target. They specify the target, prerequisites and therecipe to build the target.
Implicit Rules: Implicit rules are predefined rules that make uses when there's no explicit rule for a particular target. They are used to build common file types(e.g .o from .c) automatically.
Common Rules:
all: This is typically the first rule and builds the main target, usually the final executable or library
clean: A rule to clean the build artifacts, such as object files and the final executable
install: Used to install the built program or library to the system directories
test: A rule to run tests for the project

