>,>,                               Read the table card into blocks 1 and 2
<<+++++                            Set the value of block 0 to 5 (the number of cards in the hand)
>>>>>>>>>>+++++[>+++++++++++++<-]  Set block 11 to 'A' (Now on block 10)
>[>+>+>+>+>+<<<<<-]                Move block 11 to blocks 12 through 16 (Now on block 11)
+                                  Set block 11 to 1 for use as a flag
>++++++++++++++++++++++++
>++++
>++++++++++++++++++
>+++++++++++++
>++++++++++++++
>++++++++++                        Now blocks 12 through 17 contain the text "YESNO\n"
<<<<<<<<<<<<<<<<<                  Return to block 0
[                                  While the value of block 0 is not 0
    >>>[-]>[-]<<<                  Zero out blocks 3 and 4 and return to block 1
    [>>+>+<<<-]>>>[<<<+>>>-]       Copy the value in block 1 to block 3 (Now on block 4)
    <<[>>+>+<<<-]>>>[<<<+>>>-]     Copy the value in block 2 to block 4 (Now on block 5)
    ,,>,                           Read the next card into blocks 5 and 6
    <[<<->>-]                      Subtract block 5 from blocks 5 and 3 (Now on block 5)
    >>+<<<<[                       If block 3 is nonzero (using blocks 7 and 8)
        >>>[<<->>-]                Subtract block 6 from blocks 6 and 4 (Now on block 6)
        >>>+<<<<<[                 If block 4 is nonzero (using blocks 9 and 10)
            >>>>>-<<<<<[>>>>>>+<<<<<<-]
        ]
        >>>>>>[<<<<<<+>>>>>>-]     now on block 10
        <[                         If block 4 was zero (Now on block 9)
            >>>.>.>.>>>.           Print "YES\n"
            <<<<<<-                set block 11 to 0
            <<<<<<<<<<<[-]         set block 0 to 0
            >>>>>>>>>              return to block 9
        -]
        <<-<<<<[>>>>>+<<<<<-]      now on block 3
    ]
    >>>>>[<<<<<+>>>>>-]            now on block 8
    <[                             If block 3 was zero (Now on block 7)
        >>>>>.>.>.>>>.             Print "YES\n"
        <<<<<<-                    set block 11 to 0
        <<<<<<<<<<<[-]             set block 0 to 0
        >>>>>>>                    return to block 7
    -]
    <<<<<<<-                       Return to and decrement block 0
]
>>>>>>>>>>>                        Go to block 11
[                                  If block 11 is 1
    >>>>.>.>.                      Print "NO\n"
    <<<<<<-                        Return to and decrement block 11
]
