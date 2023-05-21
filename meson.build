project('KerberosLang', 'c',
		version : '1.0.0')

basesourcesdir = 'Source Files/'
baseincsdir = include_directories('Header Files')

basesources = ['main.c', 
			   basesourcesdir+'dArray.c',
			   basesourcesdir+'file.c',
               basesourcesdir+'lexer.c',
               basesourcesdir+'parser.c']

executable('demo', 
	       basesources, 
	       include_directories : baseincsdir)