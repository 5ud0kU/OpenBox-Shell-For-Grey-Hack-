# OpenBox-Shell-For-Grey-Hack-
The open box shell , is a hacking shell for the game Grey Hack.It's as been made with Minerva Owl Lib. It's also an open-source project that people can use or code plugin for.

(I suggest the use of Synapse ! This will make your life easier when it comes to building your projects https://gitlab.com/H3xad3cimalDev/synapse)

Note Important : if you use synapse for building your OpenBox dont forget to put the ../shell/args.config into ..myproject/bin/version/shell/args.config.
when exporting project dont forget to tell to your users to do the same.

![sudo](https://user-images.githubusercontent.com/90292445/154203974-625f0934-48e4-4f02-afd6-546e6021d1b0.png)

Note: I'm currently cleaning some weirdo bugs :) !


built-in cmds.

Generic.

-version                                           // return the current version of OpenBox.<br>
-exec [program_path] [parameter]                   // execute external sh basic program.<br>
-clear                                             // clear the terminal.

Dump.

-dump.add [ip]:[option:port]                       // add a net session.<br>
-dump.del [dump:index]                                  // remove the indexed element in the session list.<br>
-dump.drop [dump:index]                                 // use to see a particular element with the given index.<br>
-dump.sessions                                     // display sessions.<br>
-dump.self                                         // return the map it self.<br>
-dump.export                                       // use to export in the current path the session information.

Meta.

-meta.parse [text]                                 // parse metalib.dump_lib result.<br>
-meta.scan [dump:index]                            // scan a dumped service then add it to the meta session list.<br>
-meta.drop [meta:index]                                 // use to see a particular element with the given index.<br>
-meta.del [meta:index]                                  // remove the indexed element in the session list.<br>
-meta.sessions                                     // display sessions.<br>
-meta.self                                         // return the map it self.<br>
-meta.export                                       // use to export in the current path the session information.

Overflow.

overflow.test [dump:index] [memory] [buffer] [extrakey]  // test a library and return the resulting exploit type.<br>
overflow.craft [dump:index] [memory] [buffer] [extrakey] // add a payload to the deck.<br>
overflow.play                                            // play the deck and pass trough all payload card in it.<br>
overflow.drop                                            // display the deck.<br>
overflow.discard [deck:index]                            // remove a payload card from the deck.<br>
overflow.self                                            // return the map.<br>
overflow.export                                          // use to export the current deck.<br>
