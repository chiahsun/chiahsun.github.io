---
layout: page
title: vim
---

## vim cheetsheet

TODO

## vim plugins cheetsheet

[emmet cheetsheet @ emmet.io] (http://docs.emmet.io/cheat-sheet/)

# vim plugins

[10 Must have vim plugins] (http://www.openfoundry.org/en/tech-column/2244--vim-plugin)


## [Vundle] (https://github.com/VundleVim/Vundle.vim/blob/v0.10.2/doc/vundle.txt#L234-L254)

First, install a vim plugin manager. I use **Vundle**.

---


## [UltiSnipt.vim] (https://github.com/SirVer/ultisnips)


* [Tutorial 中文] (http://mednoter.com/UltiSnips.html)


---

## [emmet.vim] (http://www.vim.org/scripts/script.php?script_id=2981)

---

A plugin to expanding abbreviation like emmet. 

---

#### 1. First install it using Vundle. Put the following line in your _.vimrc_ and run **BundleInstall**.

```
Plugin 'mattn/emmet-vim'
```


If you want to have custom code snippets, you need to install **web** as well.

```
Plugin 'webapi-vim'
```

#### 2. Try to use it.

The default expand key is `ctrl+y+,`.

The animation from official site:

![animation] (https://raw.githubusercontent.com/mattn/emmet-vim/master/doc/screenshot.gif)


You can change by put the following line in your _.vimrc_. 

The following code Map the expand key to <kbd>ctrl+e</kbd>

```
let g:user_emmet_expandabbr_key = '<c-e>'
```

* [cheetsheet @ emmet.io] (http://docs.emmet.io/cheat-sheet/)

* [emmet.vim @ github] (https://github.com/mattn/emmet-vim)

* [emmet.vim @ vim script] (http://www.vim.org/scripts/script.php?script_id=2981)

* [cheetsheet for emmet-vim] (https://raw.githubusercontent.com/mattn/emmet-vim/master/TUTORIAL)

* [emmet.vim tutorial 中文] (https://www.zfanw.com/blog/zencoding-vim-tutorial-chinese.html)

* [emmet snippets 中文] (http://yanxyz.github.io/emmet-docs/customization/snippets/)

* [emmet snippets English] (http://docs.emmet.io/customization/snippets/)

* [snippets.json Example] (https://github.com/sergeche/emmet-sublime/blob/master/emmet/snippets.json)

* [tutorial @ sitepoint] (http://www.sitepoint.com/faster-workflow-mastering-emmet-part-4/)


### Q & A

#### 1. What syntax file is being used?

```
:echo b:current_syntax
```

[Original question @ superuser] (http://superuser.com/questions/686241/how-do-i-tell-what-syntax-file-is-being-used)

#### 2. How to swap between two split windows?


<kbd>ctrl+w+r</kbd>


---

#### 3. Key map in vim

```
http://vim.wikia.com/wiki/Mapping_keys_in_Vim_-_Tutorial_(Part_2)
```

---

#### 4. Solution for YouCompleteMe conflicts with UltiSnipts


```
https://github.com/Valloric/YouCompleteMe/issues/420#issuecomment-55940039
https://github.com/SirVer/ultisnips/issues/512
```

---

#### 5. List the script acticated

```
http://vim.wikia.com/wiki/List_loaded_scripts
```

### Reference

* [emmet official website] (http://docs.emmet.io/)
