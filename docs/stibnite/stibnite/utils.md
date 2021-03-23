## **traverse\_file\_structure**`#!py3 (current, function, **inner_function_args)` { #traverse-file-structure data-toc-label=traverse\_file\_structure }

Recursively traverses the given folder and applies the function to every file that it finds.

**Parameters**

> **current:** `stibnite.file_operations.FolderType` -- Source folder

> **function:** `function` -- The function that will be applied to files of the current folder

> **inner_function_args:** `dictionary of sting to object` -- Arguments of the inner function

**Returns**

> `stibnite.file_operations.FolderType` -- The same source folder

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def traverse_file_structure(current, function, **inner_function_args):
	    
	    if len(current.folders) > 0:
	        for folder in current.folders.keys():
	            traverse_file_structure(current.get_element(folder), function, **inner_function_args)
	    if len(current.files) > 0:
	        for file in current.files.keys():
	            current.files[file] = function(current.files[file], **inner_function_args)
	
	    return current
	

	```

______

