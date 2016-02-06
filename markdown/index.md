---
layout: page
title: markdown
---

## Introduction


<br> Markdown is one of the markup languages that is simple but enriched to use.

Use [Git Pages](https://pages.github.com/), it is preferable to switch to [kramdown](http://kramdown.gettalong.org/).

You can go through the [markdown tutorial] (http://markdowntutorial.com/) to understand the simplicty of it.

In this website, _kramdown_ is used since it is hosed on Git Pages. (Here is the [sytax](http://kramdown.gettalong.org/syntax.html) and [quick reference](http://kramdown.gettalong.org/quickref.html)) 

Below, we will have two versions. But if you want to host it on GitHub Pages, kramdown is flavored.

1. markdown (Some of them will not rendered rightly here.)

2. kramdown

---

### Create fenced code block (markdown)


\`\`\` <br>
Here is the fenced code block<br>
\`\`\`

```
Here is the fenced code block
```

---

### Create fenced code block (kramdown)

~~~~~
~~~
Here is the fenced code block for kramdown
~~~
~~~~~

~~~
Here is the fenced code block for kramdown
~~~


---

### Sytax highlighting for code (markdown)

\`\`\`python<br>
def hello_word():<br>
&nbsp;&nbsp;&nbsp;&nbsp;print("Hello, world!");<br>
\`\`\`


```python
def hello_word():
    print("Hello, world!");
```

---

### Sytax highlighting for code (kramdown)

~~~~~
~~~ python
def hello_word():
    print("Hello, world!");
~~~
~~~~~

~~~ python
def hello_word():
    print("Hello, world!");
~~~

---

### Sytax highlighting for code (pygment)

{% raw %}

{% highlight python %} <br> 
def hello_word(): <br>
    print("Hello, world!"); <br>
{% endhighlight %} <br>

{% endraw %}

<br>

{% highlight python %}
def hello_word():
    print("Hello, world!");
{% endhighlight %}



---

#### Display image

```
![Image on Wiki]  (https://upload.wikimedia.org/wikipedia/en/a/a9/Example.jpg)
```


![Image on Wiki] (https://upload.wikimedia.org/wikipedia/en/a/a9/Example.jpg)

---

#### Display image (kramdown)

~~~
![Image on Wiki](https://upload.wikimedia.org/wikipedia/en/a/a9/Example.jpg)
~~~


![Image on Wiki](https://upload.wikimedia.org/wikipedia/en/a/a9/Example.jpg)

<p class="bg-info"><img src="http://findicons.com/files/icons/1676/primo/48/warning_blue.png"></span>No space between ] and ( </p>

---


#### Create link (markdown)

~~~~~
[Google] (www.google.com.tw) 
~~~~~

[Google] (www.google.com.tw) 


---

#### Create link (kramdown)

~~~~~
[Google](www.google.com.tw) 
~~~~~

[Google](www.google.com.tw) 


<p class="bg-info"><img src="http://findicons.com/files/icons/1676/primo/48/warning_blue.png"></span>No space between ] and ( </p>

---

#### Comment

~~~
[comment]: <> (This is one line of comment.) 
~~~

Where the comment is `This is one line of comment.`

[comment]: <> (This is one line of comment.) 


---

### Reference 

1. [markdown tutorial in Chinese](http://markdown.tw/)

2. [markdown guides @ guides.gitgub](https://guides.github.com/features/mastering-markdown/)

3. [markdown syntax @ github](https://help.github.com/articles/basic-writing-and-formatting-syntax/)

4. [markdown cheetsheet @ github](https://enterprise.github.com/downloads/en/markdown-cheatsheet.pdf)

5. [markdown syntax @ daringfireball](http://daringfireball.net/projects/markdown/syntax#html)

6. [markdown cheetsheet @ squarespace](https://support.squarespace.com/hc/en-us/articles/206543587-Markdown-cheat-sheet)

7. [nice markdown cheetsheet @ jonschlinkert](https://gist.github.com/jonschlinkert/5854601)


Icons is provided by [FindIcons.com](http://findicons.com/icon/175920/warning_blue)
