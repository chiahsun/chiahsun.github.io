---
layout: page
title: git
---

## Add a directory to git

~~~
git init
git commit -m "commit message"
git remote add origin https://github.com/user_name/project_name.git
git push -u origin master
~~~

### Reference

* [Learning Git in 30 days](https://github.com/doggy8088/Learn-Git-in-30-days/tree/master/docs)


## [Undo the most recent commit message](http://stackoverflow.com/questions/179123/edit-an-incorrect-commit-message-in-git)

~~~
git commit --amend
~~~

or

~~~
git commit --amend -m "New message"
~~~

