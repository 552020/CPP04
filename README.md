# CPP04

## ex01

## ex02

## ex03

## ex04

## Concepts and Utilia

### Headers and Makefie

Since we use the keyword `virtual` in the header files of our classes but then the keyword doesn't appear in the cpp implementation file, if we change a function from virtual to not virtual in the header file and we run make, make will not recompile the program, cuase till now we didn't check for changes in the header files

The Makefile you've shared is set up to automatically handle dependencies for a C++ project, ensuring that any changes in your source files or headers lead to the correct files being recompiled. The lines relevant to dependency management are designed to work with the GCC compiler (or any compatible compiler) to automatically generate and include dependency information. Here's a breakdown of how these lines work:

### Defining Dependency Flags

```makefile
DEPFLAGS = -MMD -MP
```

- `-MMD`: This flag tells the compiler to generate dependency files for each `.cpp` file. These `.d` files contain Makefile rules describing the dependencies of the source file on various headers and other source files. Unlike `-MD`, `-MMD` does not include system headers in the dependency files, which is usually desirable since system headers rarely change and do not need to trigger a rebuild.
- `-MP`: This flag adds a phony target for each dependency other than the main file, preventing errors when a header file is deleted. Without `-MP`, if you removed a header file that was listed in a `.d` file, `make` would fail due to the missing file. With `-MP`, an empty rule is created for each dependency, so `make` can proceed even if a file no longer exists.

### Defining Dependency Files

```makefile
DEPS = $(OBJS:.o=.d)
```

This line converts the list of object files in `OBJS` to a list of dependency files in `DEPS` by substituting the file extension `.o` with `.d`. This means for every `.cpp` file compiled into an `.o` file, there's a corresponding `.d` file listing its dependencies.

### Including Dependency Files

```makefile
-include $(DEPS)
```

This line tells `make` to include the generated dependency files into the Makefile if they exist. The `-include` directive is used instead of `include` to prevent errors when the `.d` files do not exist (e.g., on the first build or after a `clean`). Including these files allows `make` to read the rules for each source file's dependencies directly, ensuring that any changes to included headers or other dependencies trigger a recompilation of the affected source files.

### How It Checks for Changes

When you build your project, the compiler generates `.d` files due to the `$(DEPFLAGS)` in the compilation command:

```makefile
$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@
```

These `.d` files contain Makefile-compatible rules that list each `.o` file's dependencies on source and header files. By including these `.d` files, `make` becomes aware of the dependencies. If any file listed in a `.d` file changes, `make` knows the corresponding `.o` file is out of date and must be recompiled, along with any targets depending on that `.o` file.

In summary, the dependency lines in your Makefile automatically generate and include dependency information, ensuring that your project is rebuilt correctly when source files or their dependencies change. This automation simplifies the maintenance of the Makefile, as you don't need to manually specify dependencies for each source file.
