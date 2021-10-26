The prism module in Picat provides an interface to the
PRISM system, which was developed by Taisuke Sato's group
at Tokyo Institute of Technology, and is now maintained by
Yoshitaka Kameya (https://rjida.meijo-u.ac.jp/prism/).

The directory "emu" contains makefiles for several platforms.
The directory "exs" contains several examples that use the
prism module.

A program that uses the prism module must begin with the
following declaration:

```
import prism.
```

which makes PRISM's built-ins visible to Picat. A prism
program must include a predicate, named values(I,Os), which
specifies a random variable (called a multi-valued switch
in PRISM) I and I's sample space Os. Since I can be any
term, multiple switches can share the same sample space.
The probability distribution of a switch can be set by
using the predicate set_sw(I,Ps) or learned from data by
using the predicate learn(Fs). The most important built-in
predicate in PRISM is probably the msw(I,V) predicate,
which performs a probabilistic sampling of the switch I
based on its probability distribution and binds V to the
outcome. The prism interface only provides part of the
built-ins of the original PRISM system. The list of
built-ins provided by the interface can be found at:

http://picat-lang.org/download/prism.pi

Below is the source code of the program "direction.pi":

```
import prism.

values(coin, [head,tail]).

direction(D) =>
    msw(coin,Face),
    (Face == head -> D = left; D = right).
```

The following commands illustrate how to run the program:

```
c:\picat\work\picat               % start picat_prism

Picat> cl(direction).             % compile and load the program

Picat> set_sw(coin,[0.5,0.5])     % set the probability distribution

Picat> sample($direction(D))      % sample execution
D = left

Picat> direction(D)               % sample execution
D = left

Picat> prob($direction(left),P)   % probability computation
P = 0.5

Picat> prob($direction(_),P)      % probability computation
P = 1.0

Picat> learn($[direction(left),direction(left),direction(right)])

Picat> show_sw
Switch coin: unfixed_p: head (p: 0.666666667) tail (p: 0.333333333)
```

This porting of PRISM to Picat was done by Neng-Fa Zhou while he was
a research fellow working with Vijay Saraswat at Goldman Sachs in
the summer of 2020.
