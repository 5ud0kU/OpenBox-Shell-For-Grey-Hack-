overflow = {};

overflow.deck = [];
overflow.test = function(index,addr,buffer,key)
  if typeof(index.to_int) != "number" then return "index expect a number.";
  if meta.session.len < 1 then return "theres no active session.";
  if index.to_int < 0 or index.to_int > meta.session.len then return "index out of range."

  metalib = meta.session[index.to_int].metalib;
  x = metalib.overflow(addr,buffer,key);
  return str("The exploit returns : " + typeof(x));
end function


overflow.craft = function(index,addr,buffer,key)
  if typeof(index.to_int) != "number" then return "index expect a number.";
  if meta.session.len < 1 then return "theres no active session.";
  if index.to_int < 0 or index.to_int > meta.session.len then return "index out of range.";

  card = {"idx":index,"address":addr,"buffer":buffer,"key":key,"typeof":"undefined"};
  overflow.deck.push(card);
end function

overflow.play = function()
  if overflow.deck.len < 1 then return "theres no card in the deck.";
  if meta.session.len < 1 then return "theres no active session.";

  for i in range(0,overflow.deck.len -1)
    x = overflow.deck[i];
    if x.idx.to_int > 0 or x.idx.to_int < meta.session.len then
      exploit = meta.session[x.idx.to_int].metalib.overflow(x.address,x.buffer,x.key);
      overflow.deck[i].typeof = str(typeof(exploit));
    end if
  end for

  return "the typeof deck cards as been updated."
end function

overflow.drop = function()
  if overflow.deck.len < 1 then return "theres no crafted cards in the deck.";
  text = "IDX ADR BFR KEY TPO" + char(10);
  for i in range(0,overflow.deck.len -1)
    text = text + overflow.deck[i].idx + " " + overflow.deck[i].address + " " + overflow.deck[i].buffer + " " + overflow.deck[i].key + " " + overflow.deck[i].typeof + char(10);
  end for
  text = format_columns(text);
  return text;
end function

overflow.discard = function(index)
  if typeof(index.to_int) != "number" then return "index expect a number.";
  if overflow.deck.len < 1 then return "theres no card in the deck.";
  if index.to_int < 0 or index.to_int > overflow.deck.len then return "index out of range.";
  overflow.deck.remove(index.to_int);
  return "card been deleted!";
end function

overflow.self = function()
  return str(overflow);
end function

overflow.export = function()
  if overflow.deck.len < 1 then return "theres no card in the deck.";
  get_shell.host_computer.touch(current_path,"overflow.export");
  data = "ADR BFR KEY TPO" + char(10);
  for i in range(0,overflow.deck.len -1)
    data = data + overflow.deck[i].address + " " + overflow.deck[i].buffer + " " + overflow.deck[i].key + " " + overflow.deck[i].typeof + char(10);
  end for
  data = format_columns(data);
  x = current_path + "/overflow.export";
  get_shell.host_computer.File(x).set_content(data);
  return "deck saved !";
end function

/// Here you can add various hack or boad function by example.
/// Nothing dissallow you of create a your own exploitation.
/// If you do so don't forget to add the module to the shell.h , args.config, main.c.
/// In order to make it work.
