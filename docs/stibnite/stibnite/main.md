## **main**`#!py3 (argv=None)` { #main data-toc-label=main }

??? info "Source Code" 
	```py3 linenums="1 1 2" 

	def main(argv=None):
	    argv = sys.argv if argv is None else argv
	
	    print(argv)
	
	    DocumentationManager(argv[1], argv[2], platform.system(),
	                         input_style=constants.RESTRUCTERED,
	                         output_style=constants.MARKDOWN).write_file_structure()
	
	    os.chdir(argv[2])
	
	    call(["mkdocs", "build", "--clean"])
	
	    call(["mkdocs", "serve"])
	
	    webbrowser.open("http://127.0.0.1:8000/")
	

	```

______

