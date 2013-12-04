set nu
set cindent
set autoindent
set smartindent
set tabstop=4
set shiftwidth=4
set softtabstop=4
set nobackup 
set expandtab
" 不要生成swap文件，当buffer被丢弃的时候隐藏它 
setlocal noswapfile
set mouse=a

"按F5 编译当前文件
map <F5> :w<CR> :!clear; g++ % -g <CR>
"按F6 执行
map <F6> :w<CR> :!clear; g++ % -g && (ulimit -c unlimited; ./a.out < input.txt)<CR>
"按F7 打开input.txt
map <F7> :w<CR> :!clear; vim ./input.txt;<CR>
" 按F9 粘贴模式，保持原来的格式
set pastetoggle=<F9>
 

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
    call append(line(".")+6, "#include <stack>")
    call append(line(".")+7, "#include <cmath>")
    call append(line(".")+8, "#include <cstring>")
    call append(line(".")+9, "#include <string>")
    call append(line(".")+10, "#include <map>")
    call append(line(".")+11, "#include <set>")
    call append(line(".")+12, "#define MP make_pair")
    call append(line(".")+13, "#define PB push_back")
    call append(line(".")+14, "#define SQ ((x)*(x))")
    call append(line(".")+15, "#define clr(a,b) memset(a, (b), sizeof(a))")
    call append(line(".")+16, "#define cmax(a,b) a=max(a, (b))")
    call append(line(".")+17, "#define cmin(a,b) a=min(a, (b))")
    call append(line(".")+18, "#define rep(i, n) for(int i=0;i<(n);++i)")
    call append(line(".")+19, "#define ff(i, n) for(int i=1;i<=(n);++i)")
    call append(line(".")+20, "#define ra(e, u) for(int e=head[(u)];e!=-1;e=E[e].next)")
    call append(line(".")+21, "#define rv(u, j) for(int j=0;j<adj[u].size();++j)")
    call append(line(".")+22, "using namespace std;")
    call append(line(".")+23, "")
    call append(line(".")+24, "typedef pair<int, int >PII;")
    call append(line(".")+25, "typedef long long int64;")
    call append(line(".")+26, "const double PI  = acos(-1.0);")
    call append(line(".")+27, "const int INF = 0x3f3f3f3f;")
    call append(line(".")+28, "const double eps = 1e-8;")
    call append(line(".")+29, "")
    call append(line(".")+30, "int main() {")
    call append(line(".")+31, "")
    call append(line(".")+32, "")
    call append(line(".")+33, "    return 0;")
    call append(line(".")+34, "}")
endfunc

" 定义函数SetTitle，自动插入文件头 
func SetTitle()
    call SetComment()
endfunc

