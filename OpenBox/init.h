init = function()
  if typeof(include_lib("/lib/metaxploit.so")) == "string" then exit("Missing - Metaxploit so files in /lib !");
  if typeof(include_lib("/lib/crypto.so")) == "string" then exit("Missing - Crypto so file in /lib !");
end function
