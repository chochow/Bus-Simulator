Coding style  {#codestyle}
===========

This page is a discussion of the most important rules of coding style
that I enforce within the project. It includes conventions for naming
variables, documenting code, use of namespaces.

## Conventions for naming variables
The names of variables and data members are all lowercase, with
underscores between words. Data members of classes additionally have
trailing underscores.

For example, in the class bus, I use
**speed_** to represent the speed. It has an
underscore, and is exactly the word that has the meaning. So it follows
the conventions for naming variables.


## Documenting code
Comments are very important, as they indicate your purposes, and some
relationships between some codes and others. For example, I write "class definition" for each class, at the beginning of the head files. Those
sentences imply the basic usage of those classes, which make readers
more comfortable.

However, according to Google C++ Style Guide, "while comments are very
important, the best code is self-documenting. Giving sensible names to
types and variables is much better than using obscure names that you
must then explain through comments." In this project, I tried my best
to make codes self-documenting, so it should be easy to understand them.
[See the codes in details](classes.html).



[Go back to Developer Tutorial](@ref devtutorial)
