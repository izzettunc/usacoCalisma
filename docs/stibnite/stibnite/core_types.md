## **ClassType**`#!py3 class` { #ClassType data-toc-label=ClassType }

This is a class with a sole purpose of storing information about the classes in a python file

**Parameters**

> **obj:** `object` -- A python live object of a class that is going to be documented

**class functions & static methods:** 

 - [`__init__`](#__init__)

## **\_\_init\_\_**`#!py3 (self, obj)` { #--init-- data-toc-label=\_\_init\_\_ }

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def __init__(self, obj):
	    import inspect
	    self.name = obj.__name__
	    self.obj = obj
	    self.module = obj.__module__
	    self.path = inspect.getmodule(obj).__file__
	    self.doc = obj.__doc__ or ""
	    try:
	        self.source = inspect.getsource(obj) if obj.__doc__ is None \
	            else inspect.getsource(obj).replace(obj.__doc__, '').replace('"""', '')
	    except:
	        self.source = ""
	    try:
	        self.args = str(inspect.signature(obj))
	    except:
	        self.args = ""
	    self.functions = [FunctionType(obj) for name, obj in inspect.getmembers(obj, inspect.isfunction)]
	    self.methods = [FunctionType(obj) for name, obj in inspect.getmembers(obj, inspect.ismethod)]
	

	```

______

## **FunctionType**`#!py3 class` { #FunctionType data-toc-label=FunctionType }

This is a class with a sole purpose of storing information about the functions or methods in a python file or in a python class

**Parameters**

> **obj:** `object` -- A python live object of a function or a method that is going to be documented

**class functions & static methods:** 

 - [`__init__`](#__init__)

## **\_\_init\_\_**`#!py3 (self, obj)` { #--init-- data-toc-label=\_\_init\_\_ }

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def __init__(self, obj):
	    import inspect
	    self.name = obj.__name__
	    self.name_in_list = obj.__name__
	    self.obj = obj
	    self.module = obj.__module__
	    self.path = inspect.getmodule(obj).__file__
	    self.doc = obj.__doc__ or ""
	    self.source = inspect.getsource(obj) if obj.__doc__ is None \
	        else inspect.getsource(obj).replace(obj.__doc__, '').replace('"""', '')
	    self.args = str(inspect.signature(obj))
	

	```

______

