---
layout: page
title: website 
---

Here talks about how this site is built.

<br>

## Abourt jekyll and hyde
<br>
This is a website(blog) create by [jekyll] (https://github.com/barryclark/jekyll-now) using the theme - [hyde] (https://github.com/poole/hyde).



---

## Configurations

Change the markdown parsing engine from _redcarpet_ to _kramdown_.

~~~
markdown:         redcarpet
~~~

to

~~~
markdown:         kramdown

~~~

Be sure to `gem install kramdown rouge` if you want to run it locally.

### Reference

* [Syntax Highlighting in Jekyll With Rouge](https://sacha.me/articles/jekyll-rouge/)



## Run jekyll

```
jekyll serve
```

Then, you can open the browser to _http://127.0.0.1:4000/_

## Create page

#### 1. Suppose that you want to create a page *hyde*, then create a directory of that name at the blog root.

```
mkdir hyde
```

Now your directory should have:

```
/                # root directory
/404.html
/LICENSE.md   
/README.md    
/_config.yml  
/_includes/   
/_layouts/    
/_posts/      
/_site/       
/about.md     
/atom.xml     
/hyde/           # your new directory for pages - hyde
/index.html   
/public/      
```

#### 2. Put the following lines at the front of index.md.

```
---
layout: page
title: title to display
---
```

#### Further reading

* [How to create page @ jekyllrg] (http://jekyllrb.com/docs/pages/)



### Reference

* [jekyllrb official site] (http://jekyllrb.com/)

* [jekyll-now @ github] (https://github.com/barryclark/jekyll-now)

* [hyde @ github] (https://github.com/poole/hyde)

* [tutorial @ smashingmagzine] (https://www.smashingmagazine.com/2014/08/build-blog-jekyll-github-pages/)

* [Tutorial @ loyc.net] (http://loyc.net/2014/blogging-on-github.html)
