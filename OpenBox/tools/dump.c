dump = {};
dump.session = [];

dump.add = function(address)
  if address.indexOf(":") then
    ip = address.split(":")[0];
    if not is_valid_ip(ip) then return "ip is not valid."
    port = address.split(":")[1];
    if typeof(port.to_int) != "number" then return "port expect a number."
    session = metax.net_use(ip,port.to_int);
    if session == null or session == "null" then return "net session failed.";
  else
    ip = address;
    if not is_valid_ip(ip) then return "ip is not valid";
    session = metax.net_use(ip);
    if session == null or session == "null" then return "net session failed.";
  end if
  d = session.dump_lib;
  x = {"address":address,"dump":d,"name":d.lib_name,"version":d.version};
  globals.dump.session.push(x);
  isAdded = false;
  for i in range(0,dump.session.len -1)
    if dump.session[i].address == address then isAdded = true;
  end for
  if isAdded == false then return "Session could not be added.";
  if isAdded == true then return "Session added !"
end function

dump.drop = function(index)
  if typeof(index.to_int) != "number" then return "index expect a number.";
  if dump.session.len < 1 then return "theres no active session.";
  if dump.session.len < index.to_int or index.to_int < 0 then return "index out of range.";

  card = dump.session[index.to_int];
  text = "ADR DMP NME VER" + char(10);
  text = text + card.address + " " + typeof(card.dump) + " " + card.name + " " + card.version;
  text = format_columns(text);
  return text;
end function

dump.del = function(index)
  if typeof(index.to_int) != "number" then return "index expect a number.";
  if dump.session.len < 1 then return "theres no active session.";
  if dump.session.len < index.to_int or index.to_int < 0 then return "index out of range.";
  x = dump.session.len;
  globals.dump.session.remove(index.to_int);
  if x > dump.session.len then return "session was removed.";
  if x == dump.session.len then return "session was not removed.";
end function

dump.sessions = function()
  if dump.session.len < 1 then return "theres no active session.";
  text = "IDX ADR DMP NME VER" + char(10);
  for i in range(0,dump.session.len -1)
    card = dump.session[i];
    text = text + str(i) + " " + card.address + " " + typeof(card.dump) + " " + card.name + " " + card.version + char(10);
  end for
  text = format_columns(text);
  return text;
end function

dump.self = function()
  return str(dump);
end function

dump.export = function()
	if dump.session.len < 1 then return "theres no active session."
	get_shell.host_computer.touch(current_path,"dump.export");
	data = "";
	for i in range(0,dump.session.len -1)
		data = data + dump.drop(str(i)) + char(10);
	end for
	x = current_path + "/dump.export";
	get_shell.host_computer.File(x).set_content(data);
	return "Session saved.";
end function
