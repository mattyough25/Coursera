var start = new SimpleImage("");
var hide = new SimpleImage("");

start = chop2hide(start);
hide = shift(hide);
var ans = combine(start,hide);
print(ans);