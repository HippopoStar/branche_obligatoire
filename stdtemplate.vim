" This script is intended to write most of redundant patterns that are present
" in CPP/HPP files. Activates on <F2> press.

let s:types			= {
						\'\.hpp$\|\.cpp$':
						\['/**', ' */', ' * ']
					\}

let s:nb_columns	= 80

" Sets |s:start|, |s:end| and |s:fill| variables,
" which refers respectivly to the sequence introducing a comment,
" the one closing it, and the one ensuring homogeneity.
function! s:filetype()
	let l:f = s:filename()

	let s:start		= '#'
	let s:end		= '#'
	let s:fill		= '*'

	for type in keys(s:types)
		if l:f =~ type
			let s:start		= s:types[type][0]
			let s:end		= s:types[type][1]
			let s:fill		= s:types[type][2]
		endif
	endfor

endfunction

" Returns the name of the file
function! s:filename()
	let l:filename = expand("%:t")
	if strlen(l:filename) == 0
		let l:filename = "< new >"
	endif
	return l:filename
endfunction

" Sets |s:suffix| variable to the string composed of the characters
" following the last '.' character in the name of the file
function! s:suffix()
	let l:filename		= s:filename()
	let l:suffix_pos	= strridx(l:filename, '.')
	let s:suffix		= strpart(l:filename, l:suffix_pos)
endfunction

" Sets |s:basename| variable to the string composed of the characters
" preceding the last '.' character in the name of the file
function! s:basename()
	let l:filename		= s:filename()
	let l:filename_len	= strlen(l:filename)
	let l:suffix_pos	= strridx(l:filename, '.')
	let l:suffix_len	= l:filename_len - l:suffix_pos
	let l:basename_len	= l:filename_len - l:suffix_len
	let s:basename		= strpart(l:filename, 0, l:basename_len)
endfunction

" Returns a new string composed by the given |a:str| which was appended
" given |a:character| repeatedly until lenght reached |s:nb_columns|
function! s:fill_line(str, character)
	let l:n				= s:nb_columns - strlen(a:str)
	let l:line			= a:str
	while 0 < n
		let l:line			= l:line . a:character
		let l:n				= l:n - 1
	endwhile
	return l:line
endfunction

" Prints a |s:nb_columns| wide comment line containing given |a:section_title|,
" surrounded by 2 blank lines
function! s:print_section_delimiter(section_title)
	call append(line('$'), s:start)
	call append(line('$'), s:fill_line(s:fill . a:section_title . ' ', '-'))
	call append(line('$'), s:end)
endfunction

" Prints the { Constructor(s) & Destructor(s) } section
function! s:print_constructors_and_destructors()
	call s:print_section_delimiter('Constructor(s) & Destructor(s)')
	call append(line('$'), s:basename . '::' . s:basename . '(void);')
	call append(line('$'), s:basename . '::' . s:basename . '(' . s:basename . ' const &src);')
	call append(line('$'), s:basename . '::~' . s:basename . '();')
	call append(line('$'), '')
endfunction

" Prints a generic-looking method
function! s:print_method_example()
	call append(line('$'), "void\t" . s:basename . '::' . 'my_function(int n);')
endfunction

" Prints the { Public method(s) } section
function! s:print_public_methods()
	call s:print_section_delimiter('Public method(s)')
	call s:print_method_example()
	call append(line('$'), '')
endfunction

" Prints the { Private method(s) } section
function! s:print_private_methods()
	call s:print_section_delimiter('Private method(s)')
	call s:print_method_example()
	call append(line('$'), '')
endfunction

" <Main> function of the plugin
function! s:stdtemplate()
	" Initialize script-scoped variables
	call s:filetype()
	call s:suffix()
	call s:basename()
	" Let the magic happen
	call s:print_constructors_and_destructors()
	call s:print_public_methods()
	call s:print_private_methods()
endfunction

" Bind command and shortcut
command! Stdtemplate call s:stdtemplate ()
map <F2> :Stdtemplate<CR>
