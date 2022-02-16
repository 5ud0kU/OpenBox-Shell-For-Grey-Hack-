version = function()
  print("OpenBox version 0.1");
end function

chain = [];
exec = function(cmdline,path)
  if cmdline.len < 1 then return "nothing been input except enter.";
  if cmdline[0] != "-" then return "unrecognize input.";
  cmds = Args.parse(cmdline, str(path+"/shell/args.config"));
  for i in range(0,cmds.len -1)
  	if cmds[i].indexOf("args.eval(invalid parameter : +") != null then return cmds[i];
    if cmds[i].arg == "-version" then
      globals.chain.push(@version);
    else if cmds[i].arg == "-clear" then
      globals.chain.push(@clear_screen);
    else if cmds[i].arg == "-exec" then
      globals.chain.push(@get_shell.launch(cmds[i].childs[0],cmds[i].childs[1]));
    else if cmds[i].arg == "-dump.add" then //dump module start here
      globals.chain.push(@dump.add(cmds[i].childs[0]));
    else if cmds[i].arg == "-dump.drop" then
      globals.chain.push(@dump.drop(cmds[i].childs[0]));
    else if cmds[i].arg == "-dump.del" then
      globals.chain.push(@dump.del(cmds[i].childs[0]));
    else if cmds[i].arg == "-dump.sessions" then
      globals.chain.push(@dump.sessions());
    else if cmds[i].arg == "-dump.self" then
      globals.chain.push(@dump.self());
    else if cmds[i].arg == "-dump.export" then
      globals.chain.push(@dump.export());
    else if cmds[i].arg == "-meta.parse" then //meta module start here
      globals.chain.push(@meta.parse(cmds[i].childs[0]));
    else if cmds[i].arg == "-meta.scan" then
      globals.chain.push(@meta.scan(cmds[i].childs[0]));
    else if cmds[i].arg == "-meta.drop" then
      globals.chain.push(@meta.drop(cmds[i].childs[0]));
    else if cmds[i].arg == "-meta.del" then
      globals.chain.push(@meta.del(cmds[i].childs[0]));
    else if cmds[i].arg == "-meta.sessions" then
      globals.chain.push(@meta.sessions());
    else if cmds[i].arg == "-meta.self" then
      globals.chain.push(@meta.self());
    else if cmds[i].arg == "-meta.export" then
      globals.chain.push(@meta.export());
    else if cmds[i].arg == "-overflow.test" then
      globals.chain.push(@overflow.test(cmds[i].childs[0],cmds[i].childs[1],cmds[i].childs[2],cmds[i].childs[3]));
    else
      globals.chain.push(cmds[i].arg + " as been validated, but no module was pointed.");
    end if
  end for
  return 0;
end function
