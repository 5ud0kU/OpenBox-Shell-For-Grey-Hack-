# OpenBox-Shell-For-Grey-Hack-
The open box shell , is a hacking shell for the game Grey Hack.It's as been made with Minerva Owl Lib. It's also an open-source project that people can use or code plugin for.

(I suggest the use of Synapse ! This will make your life easier when it comes to building your projects https://gitlab.com/H3xad3cimalDev/synapse)

![sudo](https://user-images.githubusercontent.com/90292445/154203974-625f0934-48e4-4f02-afd6-546e6021d1b0.png)


built-in cmds.

Generic.

-version                                           // return the current version of OpenBox.<br>
-exec [program_path] [parameter]                   // execute external sh basic program.<br>
-clear                                             // clear the terminal.

Dump.

-dump.add [ip]:[option:port]                       // add a net session.<br>
-dump.del [index]                                  // remove the indexed element in the session list.<br>
-dump.drop [index]                                 // use to see a particular element with the given index.<br>
-dump.sessions                                     // display sessions.<br>
-dump.self                                         // return the map it self.<br>
-dump.export                                       // use to export in the current path the session information.

Meta.

-meta.parse [text]                                 // parse metalib.dump_lib result.<br>
-meta.scan [dump_index]                            // scan a dumped service then add it to the meta session list.<br>
-meta.drop [index]                                 // use to see a particular element with the given index.<br>
-meta.del [index]                                  // remove the indexed element in the session list.<br>
-meta.sessions                                     // display sessions.<br>
-meta.self                                         // return the map it self.<br>
-meta.export                                       // use to export in the current path the session information.

Overflow.

overflow.test [index] [memory] [buffer] [extrakey] // test a library and return the resulting exploit type.
