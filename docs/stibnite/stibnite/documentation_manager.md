## **DocumentationManager**`#!py3 class` { #DocumentationManager data-toc-label=DocumentationManager }

This class handles with general documentation operations like reading,styling and writing.

**Parameters**

> **source_path:** `string` -- The path of the folder that contains source code

> **output_path:** `string` -- The path of the folder that is going to contain outputs

> **os_name:** `string` -- Name of the os that the user is using

> **output_style:** `string` -- Name of the style that the documentation will be written in

> **input_style:** `string` -- Name of the style that the documentation is written in

**class functions & static methods:** 

 - [`__init__`](#__init__)

 - [`get_file_structure`](#get_file_structure)

 - [`get_styled_structure`](#get_styled_structure)

 - [`write_file_structure`](#write_file_structure)

## **\_\_init\_\_**`#!py3 (self, source_path, output_path, os_name, output_style, input_style)` { #--init-- data-toc-label=\_\_init\_\_ }

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def __init__(self, source_path, output_path, os_name, output_style, input_style):
	    self.package_name = os.path.abspath(source_path).split(constants.SEPARATOR_DICT[os_name])[-1]
	    self.package_path = os.path.abspath(source_path)
	    self.documentation_name = os.path.abspath(output_path).split(constants.SEPARATOR_DICT[os_name])[-1]
	    self.documentation_path = os.path.abspath(output_path)
	    self.os_name = os_name
	    self.input_style = input_style
	    self.output_style = output_style
	    self.file_operator = file_operations.FileOperations(self.package_path,
	                                                        self.documentation_path,
	                                                        self.documentation_name,
	                                                        self.os_name)
	    self.file_structure = self.get_styled_structure(self.get_file_structure())
	

	```

## **get\_file\_structure**`#!py3 (self)` { #get-file-structure data-toc-label=get\_file\_structure }

Reads the source code and returns a file structure which is like a file tree that contains all the information about the source code.

**Returns**

> `stibnite.file_operations.FolderType` -- The root of the file structure

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def get_file_structure(self):
	    
	    return self.file_operator.read_file_structure()
	

	```

## **get\_styled\_structure**`#!py3 (self, file_structure)` { #get-styled-structure data-toc-label=get\_styled\_structure }

Stylizes and creates the documentation of the source code.

**Parameters**

> **file_structure:** `stibnite.file_operations.FolderType` -- The root of a file structure

**Returns**

> `stibnite.file_operations.FolderType` -- The same root but each documentation field in stibnite.file_operations.FileType under the file structure of the root is filled with stylized documentation text

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def get_styled_structure(self, file_structure):
	    
	    return docstring_styler.DocstringStyler(self.output_style, self.input_style).get_styled_structure(file_structure)
	

	```

## **write\_file\_structure**`#!py3 (self)` { #write-file-structure data-toc-label=write\_file\_structure }

Writes the documentation and other necessary files for mkdocs.

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def write_file_structure(self):
	    
	    self.file_operator.write_file_structure(self.file_structure)
	

	```

______

