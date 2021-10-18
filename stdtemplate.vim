let s:types			= {
						\'\.hpp$\|\.cpp$':
						\['/**', ' */', ' * ']
					\}

let s:nb_columns	= 80

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

function! s:filename()
	let l:filename = expand("%:t")
	if strlen(l:filename) == 0
		let l:filename = "< new >"
	endif
	return l:filename
endfunction

function! s:suffix()
	let l:filename		= s:filename()
	let l:suffix_pos	= strridx(l:filename, '.')
	let s:suffix		= strpart(l:filename, l:suffix_pos)
endfunction

function! s:basename()
	let l:filename		= s:filename()
	let l:filename_len	= strlen(l:filename)
	let l:suffix_pos	= strridx(l:filename, '.')
	let l:suffix_len	= l:filename_len - l:suffix_pos
	let l:basename_len	= l:filename_len - l:suffix_len
	let s:basename		= strpart(l:filename, 0, l:basename_len)
endfunction

function! s:fill_line(str, character)
	let l:n				= s:nb_columns - strlen(a:str)
	let l:line			= a:str
	while 0 < n
		let l:line			= l:line . a:character
		let l:n				= l:n - 1
	endwhile
	return l:line
endfunction

function! s:print_section_delimiter(section_title)
	call append(line('$'), s:start)
	call append(line('$'), s:fill_line(s:fill . a:section_title . ' ', '-'))
	call append(line('$'), s:end)
endfunction

function! s:print_constructors_and_destructors()
	call s:print_section_delimiter('Constructor(s) & Destructor(s)')
	call append(line('$'), s:basename . '::' . s:basename . '(void);')
	call append(line('$'), s:basename . '::' . s:basename . '(' . s:basename . ' const &src);')
	call append(line('$'), s:basename . '::~' . s:basename . '();')
	call append(line('$'), '')
endfunction

function! s:print_method_example()
	call append(line('$'), "void\t" . s:basename . '::' . 'my_function(int n);')
endfunction

function! s:print_public_methods()
	call s:print_section_delimiter('Public method(s)')
	call s:print_method_example()
	call append(line('$'), '')
endfunction

function! s:print_private_methods()
	call s:print_section_delimiter('Private method(s)')
	call s:print_method_example()
	call append(line('$'), '')
endfunction

function! s:stdtemplate()
	call s:filetype()
	call s:suffix()
	call s:basename()
	call s:print_constructors_and_destructors()
	call s:print_public_methods()
	call s:print_private_methods()
endfunction

" Bind command and shortcut
command! Stdtemplate call s:stdtemplate ()
map <F2> :Stdtemplate<CR>
