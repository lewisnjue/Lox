## backus-nur form (BNF)

to write down the rules of our language , we need a "language for writing languages" (metasyntax). the standard tool for this is **BNF** 

Here is the anotomy of a rule:

`nonterminal -> symbol_1 symbol2` 
- Noneterminals(Lowercase): these are placeholders or variables . they mean go look at another rule 
- termials(quoted "text" or CAPITALIZED): these are teh acutal tokens coming from your scanner . they are the end of the line.NUMBER means any numberic token , "==" means exactly those two characters. 

**SYTACTIC SUGAR(THE SHORCUTS)** 
writing out every single combination as a seperate rule take too much space. so, will borrow symbols from regular expression to make the rules shorter.

- | (Pipe): means OR . `bread -> "toast" | "biscuits"` means bread can be toast or biscuits 
- ()(Parenthesis) : groups things together so you can apply other rules to the whole group. 
- *(star): The thing before it appers zero or more times. 
- + (Plus): the thng before it appers one or more times. 
- ? (queiton mark): the thing before it is optinal 

**THE DERIVITION GAME** 

when your interpretor reads Lox code, it plays a game of matching. it starts at the top rule (`expression`) and tries to substitute nonterminal until the rule perfectly matches the token you typed. 
this grammer uses recursion. for example , the `binary` rule is : 

`binary -> expression operator expression` 

notice how `expression` is in teh rules body, but expression is also rule that start the whole thing ? this si the magic that allows for infinit nesting . because the binary epression contains an `expression` , which can contains another `binary` expression , you can chain togher `1+2+3+4` forever. starnrd regular expression cannot do this! 

**THE LOX GRAMMER BREAKDOWN** 

Here are teh acutal rule for the mini-language we are building . 

- `expression -> literal | unary | binary | grouping` this is the entry point. any chunk of code that produces a value is an expression. it can be one of the for things. 
- `literal -> NUMBER | STRING | "true" | "false" | "nil"` the simple expressions. just raw values 
- `grouping -> "(" expression ")"` this is how we handle parenthesis .Notice this recursion~ a grouping contains an expression inside it . 
- `unary -> ("-"|"!") expression;` operatorsion that only take one side. Like -5(negative 5) or `!true` (not true) 
- `binary -> expresion operator expresion;` operation that take two side like 5 +5 or 10 > 2 ; 
- `operator -> "=="| "!=" | "<="| ">" | ">="| "+ " | " -"| | "*"| "/";` the list of valid math and logic symbols 
