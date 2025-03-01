# Notes on DLL #

[2025-03-02T00:57:21+08:00] The reason why NTPH is using static
linking rather than dynamic linking is because NT/NTP is compiled and
invoked in a specialized environment rather than ordinary calling (In
the game there might be a certain way to prevent calling hook freely,
that explained why it requires ScriptHookV as dependency). After
testing few rounds, I found writing unit testing for NTP is bit of
challenging. So that's why there is a separate static library for
enhancement with easier testing. I guess it's able to integrate
external UI in this way as well.
