meta = {};
meta.session = [];

meta.parse = function(text)
	text = text.split(char(32));
	bufs = [];
	for i in range(0,text.len -1)
		if text[i].indexOf("<b>") != null then
			b = text[i].replace("<b>","").replace("</b>","").replace("Unsafe","").replace("*","").trim();
			if b.indexOf(".so") == null and typeof(b.replace(".","").to_int) != "number" then
				b = b.replace(".","");
				bufs.push(b);
			end if
		end if
	end for
	return bufs;
end function

meta.scan = function(index)
  if typeof(index.to_int) != "number" then return "index expect a number.";
  if dump.session.len < 1 then return "theres no active session.";
  if index.to_int < 0 and index.to_int > dump.session.len then return "index out of range.";

  x = dump.session[index.to_int];
  mems = metax.scan(x.dump);

  text = "IDX ADR LIB VER MEM BUF" + char(10);
  for i in range(0,mems.len -1)
    b = meta.parse(metax.scan_address(x.dump,mems[i]));
    if b.len > 0 then
      for e in range(0,b.len -1)
        text = text + str(e) + " " + x.address + " " + x.name + " " + x.version + " " + mems[i] + " " + b[e] + char(10);
			end for
			text = text + char(10);
    end if
  end for

  meta.session.push({"address":x.address,"drop":format_columns(text),"metalib":x.dump});

  return "Scan complete !";
end function

meta.drop = function(index)
  if typeof(index.to_int) != "number" then return "index expect a number.";
  if meta.session.len < 1 then return "theres no active session.";
	if meta.session.len < index.to_int or index.to_int < 0 then return "index out of range."

	x = meta.session[index.to_int];

	return x.drop;
end function

meta.del = function(index)
  if typeof(index.to_int) != "number" then return "index expect a number.";
  if meta.session.len < 1 then return "theres no active session.";
  if meta.session.len < index.to_int or index.to_int < 0 then return "index out of range.";
  x = meta.session.len;
  globals.meta.session.remove(index.to_int);
  if x > meta.session.len then return "session was removed.";
  if x == meta.session.len then return "session was not removed.";
end function

meta.sessions = function()
	if meta.session.len < 1 then return "theres no active session.";
	text = "IDX ADR PLD" + char(10);
	for i in range(0,meta.session.len -1)
		text = text + str(i) + " " + meta.session[i].address + " " + str(meta.session[i].drop.split(char(10)).len -3) + char(10);
	end for
	text = format_columns(text);
	return text;
end function

meta.self = function()
	return str(meta);
end function

meta.export = function()
	if meta.session.len < 1 then return "theres no active session."
	get_shell.host_computer.touch(current_path,"meta.export");
	data = "";
	for i in range(0,meta.session.len -1)
		data = data + meta.session[i].drop() + char(10);
	end for
	x = current_path + "/meta.export";
	get_shell.host_computer.File(x).set_content(data);
	return "Session saved.";
end function
