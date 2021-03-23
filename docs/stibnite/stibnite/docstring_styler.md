## **DocstringParser**`#!py3 class` { #DocstringParser data-toc-label=DocstringParser }

This class is the main class to be used for parsing supported docstrings.

**Parameters**

> **style:** `string` -- The style that documentation written in

**class functions & static methods:** 

 - [`__init__`](#__init__)

 - [`_parse_rest`](#_parse_rest)

 - [`parse_docstring`](#parse_docstring)

## **\_\_init\_\_**`#!py3 (self, style)` { #--init-- data-toc-label=\_\_init\_\_ }

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def __init__(self, style):
	    self.style = style
	

	```

## **\_parse\_rest**`#!py3 (docstring)` { #-parse-rest data-toc-label=\_parse\_rest }

Parses docstrings that are written in reStructered text.

**Parameters**

> **docstring:** `string` -- Docstring that is going to be parsed

**Returns**

> `A tuple that contains two value which are a string and a dictionary` -- A tuple which contains an explanation and information about parameters

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	@staticmethod
	def _parse_rest(docstring):
	    
	    parts = docstring.split(":rtype:")
	    return_type = parts[-1] if len(parts)>1 else None
	    parts = parts[0].split(":return:")
	    return_exp = parts[-1] if len(parts)>1 else None
	    parts = parts[0].split(":param ")
	    explanation = parts[0]
	    params_info = [{constants.NAME: constants.RETURN, constants.EXPLANATION: return_exp, constants.TYPE: return_type}]
	    for i in range(1,len(parts)):
	        param_info = {}
	        param = parts[i]
	        param_parts = param.split(":type ")
	        param_exp = param_parts[0]
	        param_type = param_parts[1] if len(param_parts)>1 else None
	        param_info[constants.NAME] = param_exp.split(":")[0]
	        param_info[constants.EXPLANATION] = ":".join(param_exp.split(":")[1:])
	        param_info[constants.TYPE] = ":".join(param_type.split(":")[1:]) if param_type is not None else None
	        params_info.append(param_info)
	
	    return explanation, params_info
	

	```

## **parse\_docstring**`#!py3 (self, docstring)` { #parse-docstring data-toc-label=parse\_docstring }

Parses given string and returns two ouput (for now) that contains all the information about the docstring.

**Parameters**

> **docstring:** `string` -- Docstring that is going to be parsed

**Returns**

> `A tuple that contains two value which are a string and a dictionary` -- A tuple which contains an explanation and information about parameters

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def parse_docstring(self, docstring):
	    
	    return eval(f"DocstringParser._parse_{self.style}(docstring)")
	

	```

______

## **DocstringStyler**`#!py3 class` { #DocstringStyler data-toc-label=DocstringStyler }

This class is the main class that stylize the information that is collected from python files into documentation with given style.

**Parameters**

> **input_style:** `string` -- The style that the documentation written in

> **output_style:** `string` -- The style that the documentation will be written in

**class functions & static methods:** 

 - [`__init__`](#__init__)

 - [`_style_class_md`](#_style_class_md)

 - [`_style_class_name_md`](#_style_class_name_md)

 - [`_style_docstring_md`](#_style_docstring_md)

 - [`_style_file_md`](#_style_file_md)

 - [`_style_func_md`](#_style_func_md)

 - [`_style_function_name_in_list_md`](#_style_function_name_in_list_md)

 - [`_style_function_name_md`](#_style_function_name_md)

 - [`_style_method_name_md`](#_style_method_name_md)

 - [`_style_source_code_md`](#_style_source_code_md)

 - [`<lambda>`](#<lambda>)

 - [`get_styled_structure`](#get_styled_structure)

## **\_\_init\_\_**`#!py3 (self, output_style, input_style)` { #--init-- data-toc-label=\_\_init\_\_ }

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def __init__(self, output_style, input_style):
	    self.output_style = output_style
	    self.input_style = input_style
	

	```

## **\_style\_class\_md**`#!py3 (clas, input_style)` { #-style-class-md data-toc-label=\_style\_class\_md }

Stylizes the given class in markdown style

**Parameters**

> **clas:** `stibnite.core_types.ClassType` -- The class that is going to be stylized

> **input_style:** `string` -- Style of the inputted docstring

**Returns**

> `stibnite.core_types.ClassType` -- The same class but name, doc, methods and functions fields are changed with stylized version of them

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	@staticmethod
	def _style_class_md(clas, input_style):
	    
	    clas.name = DocstringStyler._style_class_name_md(clas.name)
	    clas.doc = DocstringStyler._style_docstring_md(clas.doc,input_style)
	    for i in range(len(clas.methods)):
	        clas.methods[i] = DocstringStyler._style_func_md(clas.methods[i],input_style,True)
	    for i in range(len(clas.functions)):
	        clas.functions[i] = DocstringStyler._style_func_md(clas.functions[i],input_style)
	
	    return clas
	

	```

## **\_style\_class\_name\_md**`#!py3 (class_name)` { #-style-class-name-md data-toc-label=\_style\_class\_name\_md }

Stylizes the given class name in markdown style

**Parameters**

> **class_name:** `string` -- Name of the class

**Returns**

> `string` -- Class name stylized in markdown style

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	@staticmethod
	def _style_class_name_md(class_name):
	    
	    class_name = DocstringStyler.escape(class_name)
	

	```

## **\_style\_docstring\_md**`#!py3 (docstring, input_style)` { #-style-docstring-md data-toc-label=\_style\_docstring\_md }

Stylizes the docstring in markdown style

**Parameters**

> **docstring:** `string` -- The docstring that is going to be stylized

> **input_style:** `string` -- Style of the inputted docstring

**Returns**

> `string` -- The docstring stylized in markdown style

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	@staticmethod
	def _style_docstring_md(docstring, input_style):
	    
	    if input_style == constants.MARKDOWN:
	        rows = docstring.split("\n")
	        first_string = None
	        for row in rows:
	            if not row.isspace() and row != '':
	                first_string = row
	                break
	        if first_string is None:
	            return docstring
	
	        nb_indent = len(first_string) - len(first_string.lstrip())
	        for i in range(len(rows)):
	            if len(rows[i])>nb_indent:
	                rows[i] = rows[i][nb_indent:]
	        doc = '\n'.join(rows)
	        doc = f"{doc}\n\n"
	
	    else:
	        explanation, params = DocstringParser(input_style).parse_docstring(docstring)
	        doc = ""
	        rows = explanation.split("\n")
	        rows = [row for row in rows if row != "" and not row.isspace()]
	        for i in range(len(rows)):
	            rows[i] = rows[i].lstrip().rstrip()
	        explanation = " ".join(rows)
	        doc += f"{explanation}\n\n" if not explanation.isspace() and explanation != "" else ""
	        if len(params) > 1:
	            doc+=f"**Parameters**\n\n"
	            for i in range(1, len(params)):
	                if params[i][constants.TYPE] is not None:
	                    doc += f"> **{params[i][constants.NAME].lstrip().rstrip()}:** `{params[i][constants.TYPE].lstrip().rstrip()}` -- {params[i][constants.EXPLANATION].lstrip().rstrip()}\n\n"
	                else:
	                    doc += f"> **{params[i][constants.NAME].lstrip().rstrip()}:** `n/a` -- {params[i][constants.EXPLANATION].lstrip().rstrip()}\n\n"
	        if params[0][constants.TYPE] is not None or params[0][constants.EXPLANATION] is not None:
	            doc += f"**Returns**\n\n> `{params[0][constants.TYPE].lstrip().rstrip() if params[0][constants.TYPE] is not None else 'n/a'}`"
	            desc = ' -- ' + params[0][constants.EXPLANATION].lstrip().rstrip() if params[0][constants.EXPLANATION] is not None else ''
	            doc += f"{desc}\n\n"
	
	    return doc
	

	```

## **\_style\_file\_md**`#!py3 (file, input_style)` { #-style-file-md data-toc-label=\_style\_file\_md }

Stylizes the given file structure in markdown style

**Parameters**

> **file:** `stibnite.file_operations.FileType` -- The file that is going to be stylized

**Returns**

> `stibnite.file_operations.FileType` -- The same file but documentation field is filled with stylized documentation text

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	@staticmethod
	def _style_file_md(file, input_style):
	    
	    documentation = ""
	    for i in range(len(file.classes)):
	        styled_class = DocstringStyler._style_class_md(copy.deepcopy(file.classes[i]), input_style)
	        documentation += styled_class.name
	        documentation += styled_class.doc if not styled_class.doc.isspace() else ""
	        if len(styled_class.methods) > 0:
	            documentation += f"**class methods:** \n\n"
	            for method in styled_class.methods:
	                documentation += method.name_in_list
	        if len(styled_class.functions) > 0:
	            documentation += f"**class functions & static methods:** \n\n"
	            for function in styled_class.functions:
	                documentation += function.name_in_list
	
	        for method in styled_class.methods:
	            documentation += method.name
	            documentation += method.doc if not method.doc.isspace() else ""
	            documentation += method.source
	
	        for function in styled_class.functions:
	            documentation += function.name
	            documentation += function.doc if not function.doc.isspace() else ""
	            documentation += function.source
	
	        documentation += "______\n\n"
	
	    for i in range(len(file.functions)):
	        styled_function = DocstringStyler._style_func_md(file.functions[i], input_style)
	        documentation += styled_function.name
	        documentation += styled_function.doc
	        documentation += styled_function.source
	
	        documentation += "______\n\n"
	
	    file.documentation = {constants.FORMAT:constants.MARKDOWN, constants.CONTENT:documentation}
	
	    return file
	

	```

## **\_style\_func\_md**`#!py3 (func, input_style, ismethod=False)` { #-style-func-md data-toc-label=\_style\_func\_md }

Stylizes the given function or method in markdown style

**Parameters**

> **func:** `stibnite.core_types.FunctionType` -- The function that is going to be stylized

> **input_style:** `string` -- Style of the inputted docstring

> **ismethod:** `bool, optional` -- Flag that changes styling from function styling to method styling, defaults to False

**Returns**

> `stibnite.core_types.FunctionType` -- The same function or method but name, name_in_list, doc and source fields are changed with stylized version of them

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	@staticmethod
	def _style_func_md(func, input_style, ismethod=False):
	    
	    if ismethod:
	        func.name = DocstringStyler._style_method_name_md(func.obj.__self__.__class__.__name__, func.name, func.args)
	    else:
	        func.name = DocstringStyler._style_function_name_md(func.name, func.args)
	    func.name_in_list = DocstringStyler._style_function_name_in_list_md(func.name_in_list)
	    func.doc = DocstringStyler._style_docstring_md(func.doc, input_style)
	    func.source = DocstringStyler._style_source_code_md(func.source)
	
	    return func
	

	```

## **\_style\_function\_name\_in\_list\_md**`#!py3 (name_in_list)` { #-style-function-name-in-list-md data-toc-label=\_style\_function\_name\_in\_list\_md }

Stylizes the given function name to list functions of classes in markdown style

**Parameters**

> **name_in_list:** `string` -- Name of the function

**Returns**

> `string` -- Function name stylized in markdown style

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	@staticmethod
	def _style_function_name_in_list_md(name_in_list):
	    
	    return f" - [`{name_in_list}`](#{name_in_list})\n\n"
	

	```

## **\_style\_function\_name\_md**`#!py3 (function_name, args)` { #-style-function-name-md data-toc-label=\_style\_function\_name\_md }

Stylizes the given function name in markdown style

**Parameters**

> **function_name:** `string` -- Name of the function

> **args:** `string` -- Arguments seperated with ','

**Returns**

> `string` -- Function name stylized in markdown style

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	@staticmethod
	def _style_function_name_md(function_name, args):
	    
	    function_name = DocstringStyler.escape(function_name)	

	```

## **\_style\_method\_name\_md**`#!py3 (class_name, method_name, args)` { #-style-method-name-md data-toc-label=\_style\_method\_name\_md }

Stylizes the given method name in markdown style

**Parameters**

> **class_name:** `string` -- Name of the method's parent class

> **method_name:** `string` -- Name of the method

> **args:** `string` -- Arguments seperated with ','

**Returns**

> `string` -- Method name stylized in markdown style

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	@staticmethod
	def _style_method_name_md(class_name, method_name, args):
	    
	    class_name = DocstringStyler.escape(class_name)
	    method_name = DocstringStyler.escape(method_name)
	

	```

## **\_style\_source\_code\_md**`#!py3 (source_code)` { #-style-source-code-md data-toc-label=\_style\_source\_code\_md }

Stylizes the source code in markdown style

**Parameters**

> **source_code:** `string` -- The source code that is going to be stylized

**Returns**

> `string` -- The source code stylized in markdown style

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	@staticmethod
	def _style_source_code_md(source_code):
	    
	    # Fixes indentations
	    source = source_code.split("\n")
	    nb_indent = len(source[0]) - len(source[0].lstrip())
	    source_code = ""
	    for i in range(len(source)):
	        source_code += f"\t{source[i][nb_indent:]}\n"
	    return f'??? info "Source Code" \n\t```py3 linenums="1 1 2" \n\n{source_code}\n\t```\n\n'
	

	```

## **<lambda>**`#!py3 (text)` { #<lambda> data-toc-label=<lambda> }

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	escape = lambda text: text.replace('_','\\_')
	

	```

## **get\_styled\_structure**`#!py3 (self, file_structure)` { #get-styled-structure data-toc-label=get\_styled\_structure }

Stylizes the given file structure

**Parameters**

> **file_structure:** `stibnite.file_operations.FolderType` -- The root of the file structure that is going to be traversed to stylize

**Returns**

> `stibnite.file_operations.FolderType` -- The same root but each documentation field in stibnite.file_operations.FileType under the file structure of the root is filled with stylized documentation text

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def get_styled_structure(self, file_structure):
	    
	    return eval(f"utils.traverse_file_structure(file_structure, DocstringStyler._style_file_{self.output_style}, input_style=self.input_style)")
	

	```

______

