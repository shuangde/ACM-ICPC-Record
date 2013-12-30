set nu
set cindent
set autoindent
set smartindent
set tabstop=4
set shiftwidth=4
set softtabstop=4
set nobackup 
"set expandtab
" 不要生成swap文件，当buffer被丢弃的时候隐藏它 
setlocal noswapfile
set mouse=a

"按F5 编译当前文件
"map <F5> :w<CR> :!clear; g++ % -g <CR>
"按F5 编译当前文件
"\ g++ -DLOCAL % -g -o %<.o;
map <F5> :call Compile()<CR>
func Compile()
    if &filetype == 'cpp'
    exec "w"
    exec "! clear;
    \ echo 正在编译: ./% ...;
    \ echo ;
    \ g++ -DLOCAL -Wall -g %;
    \ echo ;
    \ echo 编译完成;"
    endif
endfunc


"按F6 执行
"map <F6> :w<CR> :!clear; g++ % -g && (ulimit -c unlimited; ./a.out < input.txt)<CR>
"\ ./%<.o<input.txt %<.o;"
"map <F6> :call Compile()<CR> :call Run()<CR>
map <F6> :call Run()<CR>
func Run()
    if &filetype == 'cpp'
    exec "! clear;
    \ ./a.out<input.txt %<.o;"
    endif
endfunc

"按F7 打开input.txt
map <F7> :w<CR> :!clear; vim ./input.txt;<CR>
" 按F9 粘贴模式，保持原来的格式
set pastetoggle=<F9>


" 当新建 .h .c .hpp .cpp 等文件时自动调用SetTitle 函数
"autocmd BufNewFile *.[ch],*.hpp,*.cpp exec ":call SetTitle()" 
autocmd BufNewFile *.cpp exec ":call SetTitle()" 

    " 加入注释 
func SetComment()
    " call setline(1,"") 
    call append(line("."),   "\//shuangde")
    call append(line(".")+1, "#include <iostream>") 
    call append(line(".")+2, "#include <cstdio>") 
    call append(line(".")+3, "#include <algorithm>")
    call append(line(".")+4, "#include <vector>")
    call append(line(".")+5, "#include <queue>")
    call append(line(".")+6, "#include <stack>")
    call append(line(".")+7, "#include <cmath>")
    call append(line(".")+8, "#include <cstring>")
    call append(line(".")+9, "#include <string>")
    call append(line(".")+10, "#include <map>")
    call append(line(".")+11, "#include <set>")
    call append(line(".")+12, "#include <bitset>")
    call append(line(".")+13, "#include <ext/rope>")
    call append(line(".")+14, "#define MP make_pair")
    call append(line(".")+15, "#define PB push_back")
    call append(line(".")+16, "#define SQ(x) ((x)*(x))")
    call append(line(".")+17, "#define clr(a,b) memset(a, (b), sizeof(a))")
    call append(line(".")+18, "#define cmax(a,b) a=max(a, (b))")
    call append(line(".")+19, "#define cmin(a,b) a=min(a, (b))")
    call append(line(".")+20, "#define asc(a,b) if(a>b)swap(a,b)")
    call append(line(".")+21, "#define des(a,b) if(a<b)swap(a,b)")
    call append(line(".")+22, "#define rep(i, n) for(int i=0;i<(n);++i)")
    call append(line(".")+23, "#define ff(i, n) for(int i=1;i<=(n);++i)")
    call append(line(".")+24, "#define ra(e, u) for(int e=head[(u)];e!=-1;e=E[e].next)")
    call append(line(".")+25, "#define rv(u, j) for(int j=0;j<adj[u].size();++j)")
    call append(line(".")+26, "using namespace std;")
    call append(line(".")+27, "using namespace __gnu_cxx;")
    call append(line(".")+28, "")
    call append(line(".")+29, "typedef pair<int, int >PII;")
    call append(line(".")+30, "typedef long long LL;")
    call append(line(".")+31, "")
    call append(line(".")+32, "const double PI  = acos(-1.0);")
    call append(line(".")+33, "const double eps = 1e-8;")
    call append(line(".")+34, "const int dir4[4][2]={1,0,-1,0,0,1,0,-1};")
    call append(line(".")+35, "const int dir8[8][2]={1,0,-1,0,0,1,0,-1,1,-1,1,1,-1,1,-1,-1};")
    call append(line(".")+36, "const int INF = 0x3f3f3f3f;")
    call append(line(".")+37, "const LL INF64 = 0x3f3f3f3f3f3f3f3f;")
    call append(line(".")+38, "")
    call append(line(".")+39, "int main() {")
    call append(line(".")+40, "")
    call append(line(".")+41, "")
    call append(line(".")+42, "    return 0;")
    call append(line(".")+43, "}")
endfunc

    " 定义函数SetTitle，自动插入文件头 
func SetTitle()
    call SetComment()
endfunc

