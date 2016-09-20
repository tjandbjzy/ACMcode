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

colorscheme molokai
"colorscheme solarized
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
call setline(1, "#include <iostream>")
call setline(2, "#include <cstdio>")
call setline(3, "#include <cstring>")
call setline(4, "#include <algorithm>")
call setline(5, "#include <queue>")
call setline(6, "#include <vector>")
call setline(7, "#include <cmath>")
call setline(8, "#include <cstdlib>")
call setline(9, "#include <map>")
call setline(10, "#include <stack>")
call setline(11, "#include <set>")
call setline(12, "#include <ctime>")
call setline(13, "")
call setline(14, "typedef long long ll;")
call setline(15, "")
call setline(16, "int main(){")
call setline(17, "    ")
call setline(18, "    return 0;")
call setline(19, "}")
endif
endfunc

map <S-k> <S-i>//<Esc>j<S-i><Esc>
imap <S-k> <Esc><S-i>//<Esc>j<S-i>
map <C-k> <S-i><delete><delete><Esc>j
imap <C-k> <Esc><S-i><delete><delete><Esc>j<S-i>
