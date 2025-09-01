" vim-plug
"
" Unix
" curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
"
" Windows
" iwr -useb https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim | ni $HOME/vimfiles/autoload/plug.vim -Force
"

"  设定默认解码
set encoding=utf-8

"  文件编辑在右侧
let g:termdebug_wide=1

" 关闭 vi 兼容模式
set nocompatible

" 允许退格键删除任意字符
" set backspace=2
set backspace=indent,eol,start

" 设置默认终端为 pwsh.exe
if has('win32')
    set shell=pwsh.exe
    set shellcmdflag=-NoLogo\ -NoProfile\ -ExecutionPolicy\ RemoteSigned\ -Command
    set shellquote=\"
    set shellxquote=
endif

" Windows 文本也能正常换行显示
set fileformats=unix,dos

" 行号
set number
" 如需相对行号, 另外加: set relativenumber

" 高亮当前行
set cursorline
highlight CursorLine cterm=NONE ctermbg=NONE ctermfg=NONE guibg=NONE guifg=NONE

"  统一缩进为 4
set softtabstop=4

"  设定 tab 长度为 4
set tabstop=4

"  空格替代制表符
set expandtab

"  禁止在搜索到文件两端时重新搜索
set nowrapscan

"  输入搜索内容时就显示搜索结果
set incsearch

"  搜索时高亮显示被找到的文本
set hlsearch

" 总是显示状态栏
set laststatus=2

" 显示光标当前位置
set ruler

"  打开文件类型检测功能
filetype on
filetype plugin on

"  不同文件类型采用不同缩进
filetype indent on
filetype plugin indent on

" Commenting blocks of code.
" augroup visual_commenting
"     autocmd!
"     autocmd FileType c,cpp,java,rust  let b:comment_symbol = '// '
"     autocmd FileType vim              let b:comment_symbol = '" '
"     autocmd FileType sh,vim,python    let b:comment_symbol = '# '
"     autocmd FileType tex              let b:comment_symbol = '% '
"     autocmd BufEnter * silent! vnoremap <silent> <C-_> :<C-u>keepp '<,'>s@^@\=b:comment_symbol<CR>
"     autocmd BufEnter * silent! exec 'vnoremap <silent> <C-?> :<C-u>keepp ''<,''>s@^' . b:comment_symbol . '@<CR>'
" augroup END

" ---------- 插件: vim-plug ----------
" 不指定目录时, vim-plug 会在 Linux/WSL 用 ~/.vim/plugged,
" 在 Windows 用 ~/vimfiles/plugged
" 参考: vim-plug Getting Started
" call plug#begin({dir}) 也可自定义目录
call plug#begin()

" LSP/补全: coc.nvim (发布分支)
Plug 'neoclide/coc.nvim', {'branch': 'release'}
" Plug 'tpope/vim-commentary'   " 轻量注释插件

call plug#end()

" ---------- coc.nvim 基本键位 ----------
" 跳转/查看
nmap <silent> gd <Plug>(coc-definition)
nmap <silent> gy <Plug>(coc-type-definition)
nmap <silent> gi <Plug>(coc-implementation)
nmap <silent> gr <Plug>(coc-references)
nnoremap <silent> K :call CocActionAsync('doHover')<CR>

" 保存时格式化
autocmd BufWritePre *.c,*.h,*.cpp,*.hpp,*.cc,*.ixx :silent! call CocAction('format')

" Use tab for trigger completion with characters ahead and navigate
" NOTE: There's always complete item selected by default, you may want to enable
" no select by `"suggest.noselect": true` in your configuration file
" NOTE: Use command ':verbose imap <tab>' to make sure tab is not mapped by
" other plugin before putting this into your config
inoremap <silent><expr> <TAB>
      \ coc#pum#visible() ? coc#pum#next(1) :
      \ CheckBackspace() ? "\<Tab>" :
      \ coc#refresh()
inoremap <expr><S-TAB> coc#pum#visible() ? coc#pum#prev(1) : "\<C-h>"

" Make <CR> to accept selected completion item or notify coc.nvim to format
" <C-g>u breaks current undo, please make your own choice
inoremap <silent><expr> <CR> coc#pum#visible() ? coc#pum#confirm()
                              \: "\<C-g>u\<CR>\<c-r>=coc#on_enter()\<CR>"

function! CheckBackspace() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1] =~# '\s'
endfunction
