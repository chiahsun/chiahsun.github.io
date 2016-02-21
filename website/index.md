---
layout: page
title: Website
text: Here talks about how this site is built.
---


## Abourt jekyll and hyde


This is a website(blog) create by [jekyll](https://github.com/barryclark/jekyll-now) using the theme - [hyde](https://github.com/poole/hyde). 

However, I want to test [Bootstrap](http://getbootstrap.com/), so large part of them is replaced by Bootstrap.



---

## Configurations


#### 1. Change markdown parsing engine

For _\_config.html_, change the markdown parsing engine from _redcarpet_ to _kramdown_. (default : redcarpet in _Hyde_)

The reason is that:

> [GitHub Pages will _only_ support kramdown.](https://github.com/blog/2100-github-pages-now-faster-and-simpler-with-jekyll-3-0)

~~~
markdown:         redcarpet
~~~

to

~~~
markdown:         kramdown
kramdown:
  input: GFM
  syntax_highlighter: rouge
~~~

Be sure to `gem install kramdown rouge` if you want to run it locally.

#### 2. Use Bootstrap

If you want to use Bootstrap CSS like me, you have to add the following lines to _\_includes/head.html_

~~~html
<!-- Boostrap CDN -->
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.1/css/bootstrap.min.css">
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.1/css/bootstrap-theme.min.css">
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.1/js/bootstrap.min.js"></script>
~~~

and comment out Hyde CSS

~~~html
<!--
<link rel="stylesheet" href="{{ site.baseurl }}public/css/poole.css">
<link rel="stylesheet" href="{{ site.baseurl }}public/css/hyde.css">
<link rel="stylesheet" href="http://fonts.googleapis.com/css?family=PT+Sans:400,400italic,700|Abril+Fatface">
-->
~~~

Note that syntax.css should be kept for rendering the code.


### Reference

* [Syntax Highlighting in Jekyll With Rouge](https://sacha.me/articles/jekyll-rouge/)

---

## Run jekyll

~~~
jekyll serve
~~~

Then, you can open the browser to _http://127.0.0.1:4000/_

---

## Create page

#### 1. Suppose that you want to create a page *awesomeness*, then create a directory of that name at the blog root.

~~~
mkdir awesomeness
~~~

Now your directory should have:

~~~
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
/awesomeness/    # your new directory for pages - awesomeness
/index.html   
/public/      
~~~

#### 2. Put the following lines at the front of index.md which should locate at _awesomeness/_.

~~~
---
layout: page
title: awesomeness
---
~~~

Note that the title doesn't have to conform to any retrictions, but <mark>it should not be empty</mark>.

It would be the name used on the navigation bar and title display.

### Further reading

* [How to create page @ jekyllrg](http://jekyllrb.com/docs/pages/)


## [Rouge](https://github.com/jneen/rouge/wiki/list-of-supported-languages-and-lexers) <small>syntax highlighter</small>

## [Liguid for Designers](https://github.com/Shopify/liquid/wiki/Liquid-for-Designers) <small>the engine behind Jekyll</small>

### Reference

* [jekyllrb official site](http://jekyllrb.com/)

* [jekyll-now @ github](https://github.com/barryclark/jekyll-now)

* [hyde @ github](https://github.com/poole/hyde)

* [tutorial @ smashingmagzine](https://www.smashingmagazine.com/2014/08/build-blog-jekyll-github-pages/)

* [Tutorial @ loyc.net](http://loyc.net/2014/blogging-on-github.html)
