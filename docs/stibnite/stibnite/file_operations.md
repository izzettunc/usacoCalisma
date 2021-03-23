## **FileOperations**`#!py3 class` { #FileOperations data-toc-label=FileOperations }

Main class for File Operations

**Parameters**

> **package_path:** `string` -- path of the source package

> **documentation_path:** `string` -- path of the documentation will be create

> **documentation_name:** `string` -- name of the documentation will be create

> **os_name:** `string` -- name of the os that user is using

**class functions & static methods:** 

 - [`__create_template_ignore_file`](#__create_template_ignore_file)

 - [`__init__`](#__init__)

 - [`read_file_structure`](#read_file_structure)

 - [`write_file_structure`](#write_file_structure)

## **\_\_create\_template\_ignore\_file**`#!py3 (self)` { #--create-template-ignore-file data-toc-label=\_\_create\_template\_ignore\_file }

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def __create_template_ignore_file(self):
	    with open(f"{self.documentation_path}{self.separator}ignored_prefixes_and_names.json", "w", encoding="utf-8") as json_file:
	        json_file.write(json.dumps(constants.IGNORE_JSON_TEMPLATE))
	

	```

## **\_\_init\_\_**`#!py3 (self, package_path, documentation_path, documentation_name, os_name)` { #--init-- data-toc-label=\_\_init\_\_ }

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def __init__(self, package_path, documentation_path, documentation_name, os_name):
	    self.package_path = package_path
	    self.documentation_path = documentation_path
	    self.documentation_name = documentation_name
	    self.os_name = os_name
	    self.separator = constants.SEPARATOR_DICT[self.os_name]
	

	```

## **read\_file\_structure**`#!py3 (self)` { #read-file-structure data-toc-label=read\_file\_structure }

Reads the whole package and its subpackages and returns a file structure.

**Returns**

> `stibnite.file_operations.FolderType` -- a file structure of the source package

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def read_file_structure(self):
	    
	    sys.path.insert(0,  self.package_path)
	    self.__create_template_ignore_file()
	    return build_file_tree(self.package_path, self.documentation_path, self.separator)
	

	```

## **write\_file\_structure**`#!py3 (self, file_structure)` { #write-file-structure data-toc-label=write\_file\_structure }

Writes the documentation of the whole file structure and some other necessary files to run mkdocs such as index page and yaml file.

**Parameters**

> **file_structure:** `stibnite.file_operations.FolderType` -- the root of the file structure that is going to be written

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def write_file_structure(self, file_structure):
	    
	    self.documentation_path = os.path.join(os.path.abspath(self.documentation_path), "docs")
	    if not os.path.exists(self.documentation_path):
	        os.mkdir(self.documentation_path)
	
	    current_path = f"{self.documentation_path}{self.separator}{file_structure.name}"
	    if not os.path.exists(current_path):
	        os.mkdir(current_path)
	
	    toc = write_file_tree(file_structure, current_path, self.documentation_path, self.separator, "", 1)
	
	    yml_path = os.path.join(self.separator.join(self.documentation_path.split(self.separator)[:-1]), 'mkdocs.yml')
	    if not os.path.isfile(yml_path):
	        create_yaml_file(self.documentation_name, yml_path, toc)
	
	    index_path = os.path.join(self.documentation_path, 'index.md')
	    if not os.path.isfile(index_path):
	        create_index_file(self.documentation_name, index_path, f"{self.package_path}{self.separator}")
	

	```

______

## **FileType**`#!py3 class` { #FileType data-toc-label=FileType }

This is a class that represents a python file or a leaf in a tree and contains classes and functions of the same python file.

**Parameters**

> **name:** `string` -- Name of the file

> **classes:** `list of stibnite.core_types.ClassType` -- Classes in the file

> **functions:** `list of stibnite.core_types.FunctionType` -- Functions in the file

**class functions & static methods:** 

 - [`__init__`](#__init__)

## **\_\_init\_\_**`#!py3 (self, name, classes, functions)` { #--init-- data-toc-label=\_\_init\_\_ }

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def __init__(self, name, classes, functions):
	    self.name = name
	    self.classes = classes
	    self.functions = functions
	    self.folders = None
	

	```

______

## **FolderType**`#!py3 class` { #FolderType data-toc-label=FolderType }

This is a class that represents a folder or a node in a tree and contains other files or folder in it.

**Parameters**

> **name:** `string` -- Name of the file

**class functions & static methods:** 

 - [`__init__`](#__init__)

 - [`add_file`](#add_file)

 - [`add_folder`](#add_folder)

 - [`get_element`](#get_element)

## **\_\_init\_\_**`#!py3 (self, name)` { #--init-- data-toc-label=\_\_init\_\_ }

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def __init__(self, name):
	    self.name = name
	    self.folders = {}
	    self.files = {}
	

	```

## **add\_file**`#!py3 (self, file)` { #add-file data-toc-label=add\_file }

Appends the given file to its file list.

**Parameters**

> **file:** `stibnite.file_operations.FileType` -- File that is going to be added

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def add_file(self, file):
	    
	    self.files[file.name] = file
	

	```

## **add\_folder**`#!py3 (self, folder)` { #add-folder data-toc-label=add\_folder }

Appends the given folder to its folder list.

**Parameters**

> **folder:** `stibnite.file_operations.FolderType` -- Folder that is going to be added

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def add_folder(self, folder):
	    
	    self.folders[folder.name] = folder
	

	```

## **get\_element**`#!py3 (self, name)` { #get-element data-toc-label=get\_element }

Returns the file/folder with the given name if this folder contains it.

**Parameters**

> **name:** `string` -- Name of the file/folder

**Returns**

> `stibnite.file_operations.FileType or stibnite.file_operations.FolderType or None` -- The file/folder with the given name

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def get_element(self, name):
	    
	    if name in self.folders:
	        return self.folders[name]
	    elif name in self.files:
	        return self.files[name]
	    else:
	        return None
	

	```

______

## **build\_file\_tree**`#!py3 (package_path, documentation_path, separator)` { #build-file-tree data-toc-label=build\_file\_tree }

Recursively reads and builds the file structure.

**Parameters**

> **package_path:** `string` -- the source path that is going to be read

> **documentation_path:** `string` -- the path of the folder that is going to contain outputs

> **separator:** `string` -- seperator of the file system of the os

**Returns**

> `stibnite.file_operations.FolderType` -- the root of a file tree

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def build_file_tree(package_path, documentation_path, separator):
	    
	    for path, dirs, files in os.walk(package_path):
	        if len(dirs) == 0 and len(files) == 0:
	            return None
	        current_node = FolderType(path.split(separator)[-1])
	        for directory in dirs:
	            if not is_ignored(directory, f"{documentation_path}{separator}"):
	                node_candidate = build_file_tree(os.path.join(path, directory), documentation_path, separator)
	                if node_candidate is not None:
	                    current_node.add_folder(node_candidate)
	
	        for file in files:
	            if not is_ignored(file, f"{documentation_path}{separator}") and file.split('.')[-1] == "py":
	                module = import_module(file.split('.')[0], os.path.join(path, file))
	
	                classes = [
	                    core_types.ClassType(obj)
	                    for name, obj in inspect.getmembers(module, inspect.isclass)
	                    if obj.__module__ == module.__name__
	                ]
	                functions = [
	                    core_types.FunctionType(obj)
	                    for name, obj in inspect.getmembers(module, inspect.isfunction)
	                    if obj.__module__ == module.__name__
	                ]
	
	                current_node.add_file(FileType(file,
	                                               functions=functions,
	                                               classes=classes))
	        return current_node
	

	```

______

## **create\_index\_file**`#!py3 (project_name, index_file_path, package_path)` { #create-index-file data-toc-label=create\_index\_file }

Creates and writes the index file.

**Parameters**

> **project_name:** `string` -- Name of the project

> **index_file_path:** `string` -- The path of the index file that is going to be written at

> **package_path:** `string` -- path of the source package

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def create_index_file(project_name, index_file_path, package_path):
	    
	    index_file = open(index_file_path, "w", encoding="utf-8")
	    try:
	        with open(f"{package_path}README.md", "r", encoding="utf-8") as fh:
	            long_description = fh.read()
	    except:
	        long_description = ""
	    content = f# Welcome to {project_name}
	{long_description}
	    index_file.writelines(content)
	    index_file.close()
	

	```

______

## **create\_yaml\_file**`#!py3 (project_name, yaml_file_path, toc)` { #create-yaml-file data-toc-label=create\_yaml\_file }

Creates and writes the yaml file.

**Parameters**

> **project_name:** `string` -- name of the project

> **yaml_file_path:** `string` -- the path of the yaml file that is going to be written at

> **toc:** `string` -- contents of the yaml file

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def create_yaml_file(project_name, yaml_file_path, toc):
	    
	    yaml_file = open(yaml_file_path, "w", encoding="utf-8")
	    content = fsite_name: {project_name}
	theme:
	  name: 'material'
	  palette:
	    primary: indigo
	  features:
	    - navigation.tabs
	  icon:
	    repo: fontawesome/brands/git-alt
	repo_name: csci-arch/stibnite
	repo_url: https://github.com/csci-arch/stibnite
	nav:
	    - Home: index.md
	{toc}
	markdown_extensions:
	    - toc:
	        toc_depth: 3
	        permalink: True
	    - extra
	    - smarty
	    - codehilite
	    - admonition
	    - pymdownx.details
	    - pymdownx.superfences
	    - pymdownx.emoji
	    - pymdownx.inlinehilite
	    - pymdownx.magiclink
	    
	    yaml_file.writelines(content)
	    yaml_file.close()
	

	```

______

## **import\_module**`#!py3 (module_name, module_path)` { #import-module data-toc-label=import\_module }

Import the given module and returns an object of it.

**Parameters**

> **module_name:** `string` -- Name of the module that is going to be imported

> **module_path:** `string` -- Path of the module that is going to be imported

**Returns**

> `object` -- A live object of the imported module

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def import_module(module_name, module_path):
	    
	    spec = module_loader.spec_from_file_location(module_name, module_path)
	    module = module_loader.module_from_spec(spec)
	    sys.modules[module_name] = module
	    spec.loader.exec_module(module)
	    return module
	

	```

______

## **is\_ignored**`#!py3 (name, documentation_path)` { #is-ignored data-toc-label=is\_ignored }

Checks if the given name has a ignored prefix or name.

**Parameters**

> **name:** `string` -- file or folder name

> **documentation_path:** `string` -- path of the documentation

**Returns**

> `bool` -- has a ignored prefix, name or not

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def is_ignored(name, documentation_path):
	    
	    ignored_dict = json.loads(get_json_file(documentation_path))
	    for prefix in ignored_dict["prefixes"]:
	        if name[:len(prefix)] == prefix:
	            return True
	    if name in ignored_dict['names']:
	        return True
	    return False
	

	```

______

## **write\_file\_tree**`#!py3 (element, current_path, output_path, separator, toc, depth)` { #write-file-tree data-toc-label=write\_file\_tree }

Recursively writes the documentation and creates the yaml file.

**Parameters**

> **element:** `stibnite.file_operations.FolderType` -- the current folder in the file tree

> **current_path:** `string` -- path of the current folder in the file tree

> **output_path:** `string` -- the path of the folder that is going to contain outputs

> **separator:** `string` -- seperator of the file system of the os

> **toc:** `string` -- contents of the yaml file

> **depth:** `int` -- the depth of the recursive function currently in

**Returns**

> `string` -- contents of the yaml file

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def write_file_tree(element, current_path, output_path, separator, toc, depth):
	    
	    toc += "    " * depth + "- " + element.name + ":\n"
	    if len(element.folders) > 0:
	        for name, folder in element.folders.items():
	            new_path = f'{current_path}{separator}{name}'
	            if not os.path.exists(new_path):
	                os.mkdir(new_path)
	            toc = write_file_tree(folder, new_path, output_path, separator, toc, depth+1)
	    if len(element.files) > 0:
	        for name, file in element.files.items():
	            if file.documentation[constants.CONTENT] != "":
	                file_p = open(f"{current_path}{separator}{name.split('.')[0]}.{file.documentation[constants.FORMAT]}", "w",
	                              encoding="utf-8")
	                file_p.write(file.documentation[constants.CONTENT])
	                file_p.close()
	
	                toc += "    " * (depth + 1) + "- " + f"{'/'.join(current_path[len(output_path)+1:].split(separator))}" \
	                                                     f"/{name.split('.')[0]}.{file.documentation[constants.FORMAT]}\n"
	    return toc
	

	```

______

