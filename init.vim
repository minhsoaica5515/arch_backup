call plug#begin('~/.config/nvim/plugged')

"nerdtree
Plug 'preservim/nerdTree' 
Plug 'ryanoasis/vim-devicons'
Plug 'tiagofumo/vim-nerdtree-syntax-highlight'

"fzf
Plug 'junegunn/fzf', 
		\ { 'do': { -> fzf#install() } } 
Plug 'junegunn/fzf.vim'

"status bar
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'

"terminal
Plug 'voldikss/vim-floaterm'

"accessories
Plug 'jiangmiao/auto-pairs'
Plug 'alvan/vim-closetag'
Plug 'mattn/emmet-vim' 
Plug 'preservim/nerdcommenter'
Plug 'liuchengxu/vista.vim'

"auto complete
Plug 'neoclide/coc.nvim', {'branch': 'release'}

"debug
Plug 'puremourning/vimspector'

call plug#end()

let nvim_settings_dir = '~/.config/nvim/vimconfig/'
execute 'source '.nvim_settings_dir.'vimconf.vim'
execute 'source '.nvim_settings_dir.'airline.vim'
execute 'source '.nvim_settings_dir.'coc.vim'
execute 'source '.nvim_settings_dir.'floaterm.vim'
execute 'source '.nvim_settings_dir.'nerdcommenter.vim'
execute 'source '.nvim_settings_dir.'nerdtree.vim'
execute 'source '.nvim_settings_dir.'fzf.vim'
execute 'source '.nvim_settings_dir.'vista.vim'
execute 'source '.nvim_settings_dir.'vimspector.vim'
