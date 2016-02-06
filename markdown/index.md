---
layout: page
title: markdown
---

## Introduction


<br> Markdown is one of the markup languages that is simple but enriched to use.

Use [Git Pages](https://pages.github.com/), it is preferable to switch to [kramdown](http://kramdown.gettalong.org/).

You can go through the [markdown tutorial] (http://markdowntutorial.com/) to understand the simplicty of it.

In this website, _kramdown_ is used since it is hosed on Git Pages.

Below, we will have two versions.

1. markdown

2. kramdwon

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


---

### Reference 

1. [markdown tutorial in Chinese] (http://markdown.tw/)

2. [markdown guides @ guides.gitgub] (https://guides.github.com/features/mastering-markdown/)

3. [markdown syntax @ github] (https://help.github.com/articles/basic-writing-and-formatting-syntax/)

4. [markdown cheetsheet @ github] (https://enterprise.github.com/downloads/en/markdown-cheatsheet.pdf)

5. [markdown syntax @ daringfireball] (http://daringfireball.net/projects/markdown/syntax#html)

6. [markdown cheetsheet @ squarespace] (https://support.squarespace.com/hc/en-us/articles/206543587-Markdown-cheat-sheet)

7. [nice markdown cheetsheet @ jonschlinkert] (https://gist.github.com/jonschlinkert/5854601)
