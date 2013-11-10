" 不要使用vi的键盘模式，而是vim自己的 set nocompatible
 
" 语法高亮
syntax on
 
" 不让vim发出讨厌的滴滴声 
set noerrorbells 
"1.消除shell的报警声，就是按tab键不对的响声：
"    在/etc/inputrc反注释第21行：
"        set bell-style none      保存并重启系统即可。
"2.消除vi编辑器里的报警声：
"    在/etc/bash.bashrc中加入一行：
"        set term -blength 0
 
" 在被分割的窗口间显示空白，便于阅读 
set fillchars=vert:\ ,stl:\ ,stlnc:\ 
 
" 状态行颜色 
highlight StatusLine guifg=SlateBlue guibg=Yellow 
highlight StatusLineNC guifg=Gray guibg=White 
 
" 命令行（在状态行下）的高度，默认为1，这里是2 
set cmdheight=1
 
" 不要备份文件（根据自己需要取舍） 
set nobackup 
 
" history文件中需要记录的行数 
set history=100
 
" 用空格键来开关折叠 
" set foldenable 
" set foldmethod=manual 
" nnoremap <space> @=((foldclosed(line('.')) < 0) ? 'zc':'zo')<CR> 
 
" 使回格键（backspace）正常处理indent, eol, start等 
set backspace=2 
 
" C语言风格
set cindent
set autoindent
set smartindent
 
" 把tab拓展为空格
set expandtab
set tabstop=4
set softtabstop=4
set shiftwidth=4
     
" 显示行号【nu】
set nu
 
" 在状态行上显示光标所在位置的行号和列号
set ruler
set rulerformat=%20(%2*%<%f%=\ %m%r\ %3l\ %c\ %p%%%)
 
 
" 不要生成swap文件，当buffer被丢弃的时候隐藏它 
setlocal noswapfile
set bufhidden=hide
 
" 搜索时忽略大小写，但在有一个或以上大写字母时仍保持对大小写敏感
set ignorecase smartcase 
 
 
set mouse=a
set selection=exclusive
set selectmode=mouse,key
 
set report=0
"set nohlsearch
 
set clipboard=unnamedplus

" 配置多语言环境
if has("multi_byte")
" UTF-8 编码
set encoding=utf-8
set termencoding=utf-8
set formatoptions+=mM
set fencs=utf-8,gbk
 
" 高亮显示普通txt文件（需要txt.vim脚本） 
au BufRead,BufNewFile * setfiletype txt 
 
" 侦测文件类型 
filetype on
 
" 能够漂亮地显示.NFO文件 
set encoding=utf-8 
function! SetFileEncodings(encodings) 
let b:myfileencodingsbak=&fileencodings 
let &fileencodings=a:encodings 
endfunction 
function! RestoreFileEncodings() 
let &fileencodings=b:myfileencodingsbak 
unlet b:myfileencodingsbak 
endfunction 
 
au BufReadPre *.nfo call SetFileEncodings('cp437')|set ambiwidth=single au BufReadPost *.nfo call RestoreFileEncodings() 
 
let g:SuperTabDefaultCompletionType = "context"
 
let g:snips_trigger_key='<F2>' 
 
" 方便分辨是否在插入模式，插入模式是I字型，不然就是方块。
let &t_SI = "\<Esc>]50;CursorShape=1\x7"
let &t_EI = "\<Esc>]50;CursorShape=0\x7"
 
if has("autocmd")  
    au InsertEnter * silent execute "!gconftool-2 --type string --set /apps/gnome-terminal/profiles/Default/cursor_shape ibeam"  
    au InsertLeave * silent execute "!gconftool-2 --type string --set /apps/gnome-terminal/profiles/Default/cursor_shape block"  
    au VimLeave * silent execute "!gconftool-2 --type string --set /apps/gnome-terminal/profiles/Default/cursor_shape ibeam"  
endif  
 
 
 
"按F5 编译当前文件
map <F5> :call Compile()<CR>
func Compile()
if &filetype == 'cpp'
exec "w"
exec "! clear;
\ echo 正在编译: ./% ...;
\ echo ;
\ g++ -DLOCAL % -g -o %<.o;
\ echo ;
\ echo 编译完成;"
endif
endfunc
 
 
"按Ctrl－F5 调试当前文件
map <C-F5> :call Debug()<CR>
func Debug()
if &filetype == 'cpp'
exec "w"
exec "! clear;
\ echo 正在编译: ./% ...;
\ echo ;
\ g++ % -g -DLOCAL -o %<.o;
\ echo ;
\ echo 编译完成,开始调试;
\ gdb %<.o;"
endif
endfunc
 
"按F6 执行
map <F6> :call Run()<CR>
func Run()
if &filetype == 'cpp'
exec "! clear;
\ ./%<.o<input.txt %<.o;"
endif
endfunc
 
"按F7 打开input.txt
map <F7> :call OpenInput()<CR>
func OpenInput()
exec "! clear;
\ vim ./input.txt;"
endfunc
 
 
" 按F9 粘贴模式，保持原来的格式
set pastetoggle=<F9>
 
" 实现vim中<C-A>全选，<C-C>复制，<C-X>剪切的功能： 
map <C-X> d  
map <C-A> <Esc>ggVG  
endif


" 当新建 .h .c .hpp .cpp 等文件时自动调用SetTitle 函数
autocmd BufNewFile *.[ch],*.hpp,*.cpp exec ":call SetTitle()" 

    " 加入注释 
func SetComment()
   " call setline(1,"") 
    call append(line("."),   "\//shuangde")
    call append(line(".")+1, "#include <iostream>") 
    call append(line(".")+2, "#include <cstdio>") 
    call append(line(".")+3, "#include <algorithm>")
    call append(line(".")+4, "#include <vector>")
    call append(line(".")+5, "#include <queue>")
    call append(line(".")+6, "#include <cmath>")
    call append(line(".")+7, "#include <cstring>")
    call append(line(".")+8, "#include <string>")
    call append(line(".")+9, "#include <map>")
    call append(line(".")+10, "#include <set>")
    call append(line(".")+11, "#define MP make_pair")
    call append(line(".")+12, "#define SQ ((x)*(x))")
    call append(line(".")+13, "#define rep(i, n) for(int i=0;i<n;++i)")
    call append(line(".")+14, "#define ff(i, n) for(int i=1;i<=n;++i)")
    call append(line(".")+15, "using namespace std;")
    call append(line(".")+16, "")
    call append(line(".")+17, "typedef pair<int, int >PII;")
    call append(line(".")+18, "typedef long long int64;")
    call append(line(".")+19, "const double PI  = acos(-1.0);")
    call append(line(".")+20, "const int INF = 0x3f3f3f3f;")
    call append(line(".")+21, "const double eps = 1e-8;")
    call append(line(".")+22, "")
    call append(line(".")+23, "int main() {")
    call append(line(".")+24, "")
    call append(line(".")+25, "")
    call append(line(".")+26, "    return 0;")
    call append(line(".")+27, "}")

endfunc

" 定义函数SetTitle，自动插入文件头 
func SetTitle()
    call SetComment()
endfunc
