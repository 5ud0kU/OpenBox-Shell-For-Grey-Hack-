overflow = {};

overflow.test = function(index,addr,buffer,key)
  if typeof(index.to_int) != "number" then return "index expect a number.";
  if meta.session.len < 1 then return "theres no active session.";
  if index.to_int < 0 or index.to_int > meta.session.len then return "index out of range."

  metalib = meta.session[index.to_int].metalib;
  x = metalib.overflow(addr,buffer,key);
  return str("The exploit returns : " + typeof(x));
end function

/// Here you can add various hack or boad function by example.
/// Nothing dissallow you of create a your own exploitation.
/// If you do so don't forget to add the module to the shell.h , args.config, main.c.
/// In order to make it work.
