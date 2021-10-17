let s:types		= {
			\'\.hpp$\|\.cpp$':
			\['/**', ' * ', ' */']
			\}

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

function! s:print_constructors_and_destructors()
	call append(line('$'), s:basename)
endfunction

function! s:stdtemplate()
	call s:filetype()
	call s:suffix()
	call s:basename()
	call s:print_constructors_and_destructors()
endfunction

" Bind command and shortcut
command! Stdtemplate call s:stdtemplate ()
map <F2> :Stdtemplate<CR>
