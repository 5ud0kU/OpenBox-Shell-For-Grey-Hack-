/////////////////////////////////////////////////////////////////////

//OpenBox is a script for Grey Hack. The engine use Minerval Mol Lib.
//Don't worry all the needed headers have been put in ..dll/headers.h.
//The script is a open hacking shell.

//The h files are made to not be compiled, do so if needed.
//It simpler to modify the open box. It has been thinked that way.
//The c files are considered as to be compiled. 

///IMPORTANT DONT FORGET TO CHANGE THE PATHING.

//importing dlls
import_code("/home/a/OpenBox/dll/prototype.h");
import_code("/home/a/OpenBox/dll/args.h");
import_code("/home/a/OpenBox/dll/math.h");
import_code("/home/a/OpenBox/dll/string.h");
import_code("/home/a/OpenBox/dll/graph.h");
import_code("/home/a/OpenBox/dll/algo.h");
metax = include_lib("/lib/metaxploit.so");
crypt = include_lib("/lib/crypto.so");

//importing main codes.
import_code("/home/a/OpenBox/init.h");
import_code("/home/a/OpenBox/shell/shell.h");
import_code("/home/a/OpenBox/tools/dump.c");
import_code("/home/a/OpenBox/tools/meta.c");
import_code("/home/a/OpenBox/tools/overflow.c");

// Your importation here //

/////////////////////////////////////////////////////////////////////

//Colorize it !
colorize = function(text)
  msg = "";
  for i in range(0,text.len -1)
    color = "";
    while(color.len != 7)
      v3 = Math.vector3(floor((rnd * 255) + 1),floor((rnd * 255) + 1),floor((rnd * 255) + 1));
      color = Graph.rgb(v3);
    end while
    msg = msg + Graph.color(text[i],color);
  end for
  msg = Graph.bold(msg);
  return msg;
end function

//Shell Loop.
main = function()
  tag = "[OpenBox]--{"+ current_path +"@"+ active_user + "}~$ ";
  x = user_input(colorize(tag));
  val = exec(x,parent_path(program_path));
  if val == 0 then
    //accessing the global chain , dont forget to delete the history.
    if chain.len > 0 then
      for i in range(0,chain.len -1)
        if chain[i] != null then
          if typeof(chain[i]) == "string" then
            text = chain[i].split(char(10));
            for e in range(0,text.len -1)
              print(colorize("||--(~) ") + text[e]);
            end for
          else
            chain[i];
          end if
        end if
      end for
    end if
  else
    print(colorize("||--(~) ") + val);
  end if
  globals.chain = []; //reseting the chain engine.
  main;
end function
init();
main();
