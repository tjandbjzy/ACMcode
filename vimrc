set encoding=utf-8
colorscheme torte
syntax on
set clipboard+=unnamed
set number
set showcmd
set hls
filetype on
filetype indent on
filetype plugin on
colorscheme ron
set ts=4
set sw=4

"colorscheme molokai
colorscheme solarized
"colorscheme dracula

set lines=100 columns=60


set guifont=Monaco:h15
"set guifont=Courier\ New:h20

nmap ,u :0,yank+<cr>
nmap ,y mkgg"+yG`k
nmap ,p "+p
nmap ,s :w<cr>:sh<cr>
nmap ,/ I//<esc>
nmap ,\ I<del><del><esc>
"inoremap ( ()<ESC>i
"inoremap [ []<ESC>i
"inoremap { {}<ESC>i
"inoremap < <><ESC>i
"inoremap " ""<ESC>i
"inoremap ' ''<ESC>i
imap { {}<ESC>i<CR><ESC>O
"imap { {}<ESC>i<CR><ESC>V<O
set smartindent
" 智能对齐
"
set autoindent
" " 自动对齐
set tabstop=4
set expandtab
set shiftwidth=4
autocmd BufNewFile *.cpp exec ":call SetTitle()"
func SetTitle()
if &filetype == 'cpp'
"call setline(1, "/**==================================")
"call setline(2, " | Author: tjandbj")
"call setline(3, " | OJ: ")
"call setline(4, " | Kind: ")
"call setline(5, " | Date: ")
"call setline(6, " | Describe:")
"call setline(7, " |          ")
"call setline(8, " |          ")
"call setline(9, " =================================**/")
"call setline(10, "")
call setline(1, "#include <iostream>")
call setline(2, "#include <cstdio>")
call setline(3, "#include <cstring>")
call setline(4, "#include <algorithm>")
call setline(5, "#include <queue>")
call setline(6, "#include <vector>")
call setline(7, "#include <cmath>")
call setline(8, "#include <cstdlib>")
call setline(9, "")
call setline(10, "typedef long long ll;")
call setline(11, "")
call setline(12, "int main(){")
call setline(13, "    ")
call setline(14, "    return 0;")
call setline(15, "}")
endif
endfunc

map <S-k> <S-i>//<Esc>j<S-i><Esc>
imap <S-k> <Esc><S-i>//<Esc>j<S-i>
map <C-k> <S-i><delete><delete><Esc>j
imap <C-k> <Esc><S-i><delete><delete><Esc>j<S-i>


