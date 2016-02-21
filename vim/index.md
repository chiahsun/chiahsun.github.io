---
layout: page
title: vim
text: a powerful text editor
---

This website is built by coding on [_vim_](http://www.vim.org/).

There is a steep learning curve for _vim_.

However, once you are killed at it, you can code fast with ease.

---

# Vim Cheetsheet

#### [Show vim default key bindings](http://stackoverflow.com/questions/2483849/detect-if-a-key-is-bound-to-something-in-vim)

~~~
:help index 
~~~

---

# Vim plugins

[10 Must have vim plugins](http://www.openfoundry.org/en/tech-column/2244--vim-plugin)


---

## [Vundle](https://github.com/VundleVim/Vundle.vim/blob/v0.10.2/doc/vundle.txt#L234-L254) <small>Vim plugin manager</small>

First, install a vim plugin manager. I use **Vundle**.

---

## [YouCompletMe](https://github.com/Valloric/YouCompleteMe) <small>A powerful auto completion plugin, especially for C-familty support. </small>

#### How to map the YCM fixit key?

The following code in `.vimrc' would map the FixIt command to <kbd>, f</kbd> where my leader key is <kbd>,</kbd>

~~~
let mapleader=","
map <leader>f :YcmCompleter FixIt<CR>
~~~

#### Use YVM to jump to definition

Use <kbd>, j d</kbd> to jump to definition.

~~~
nnoremap <leader>jd :YcmCompleter GoToDefinitionElseDeclaration<CR>
~~~



#### My .ycm\_extra\_conf.py (MAC OSX)

Without corrent settings, it cannot find the standard library and perform auto completion. (e.g. unordered_map)

~~~
flags = [
    '-Wall',
    '-std=c++11',
    '-stdlib=libc++',
    '-x',
    'c++',
    '-I',
    '.',
    '-isystem',
    '/Library/Developer/CommandLineTools/usr/include/c++/v1'
]
~~~

---

## [UltiSnipt.vim](https://github.com/SirVer/ultisnips)


* [Tutorial 中文](http://mednoter.com/UltiSnips.html)


---

## [emmet.vim](http://www.vim.org/scripts/script.php?script_id=2981) <small>A plugin to expanding abbreviation like emmet for web development. (HTML/CSS) </small>


#### 1. First install it using Vundle. Put the following line in your _.vimrc_.

~~~
Plugin 'mattn/emmet-vim'
~~~

and in vim, type <kbd>shift + :</kbd> in command mode input:

~~~
: BundleInstall
~~~

Vundle will install the plugins for you automatically.

If you want to have custom code snippets, you need to install **webapi** as well.

~~~
Plugin 'mattn/webapi-vim'
~~~

#### 2. Let's use it.

The default expand key is <kbd>ctrl + y + ,</kbd>.

Below is the animation from official site:

![animation](https://raw.githubusercontent.com/mattn/emmet-vim/master/doc/screenshot.gif)


You can change the expand key by put the following line in your _.vimrc_. 

The following code maps the expand key to <kbd>ctrl + e</kbd>

~~~
let g:user_emmet_expandabbr_key = '<c-e>'
~~~

#### Reference

* [emmet official website](http://docs.emmet.io/)

* [cheetsheet @ emmet.io](http://docs.emmet.io/cheat-sheet/)

* [emmet.vim @ github](https://github.com/mattn/emmet-vim)

* [emmet.vim @ vim script](http://www.vim.org/scripts/script.php?script_id=2981)

* [cheetsheet for emmet-vim](https://raw.githubusercontent.com/mattn/emmet-vim/master/TUTORIAL)

* [emmet.vim tutorial 中文](https://www.zfanw.com/blog/zencoding-vim-tutorial-chinese.html)

* [emmet snippets 中文](http://yanxyz.github.io/emmet-docs/customization/snippets/)

* [emmet snippets English](http://docs.emmet.io/customization/snippets/)

* [snippets.json Example](https://github.com/sergeche/emmet-sublime/blob/master/emmet/snippets.json)

* [tutorial @ sitepoint](http://www.sitepoint.com/faster-workflow-mastering-emmet-part-4/)

---

### Selected Q & A for vim

#### 1. What syntax file is being used?

~~~ 
:echo b:current_syntax
~~~

[Original question @ superuser](http://superuser.com/questions/686241/how-do-i-tell-what-syntax-file-is-being-used)

---

#### 2. How to swap between two split windows?

<kbd>ctrl + w + r</kbd>


---

#### 3. Key map in vim

~~~
http://vim.wikia.com/wiki/Mapping_keys_in_Vim_-_Tutorial_(Part_2)
~~~

---

#### 4. Solution for YouCompleteMe conflicts with UltiSnipts


~~~
https://github.com/Valloric/YouCompleteMe/issues/420#issuecomment-55940039
https://github.com/SirVer/ultisnips/issues/512
~~~

---

#### 5. List the script activated

~~~
http://vim.wikia.com/wiki/List_loaded_scripts
~~~

