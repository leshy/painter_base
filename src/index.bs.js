// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var JsSerial$Base = require("./JsSerial.bs.js");
var ParserReadline = require("@serialport/parser-readline");

var port = JsSerial$Base.createSerial("/dev/ttyUSB0", undefined, /* () */0);

var readline = new ParserReadline();

port.pipe(readline);

readline.on("line", (function (line) {
        console.log(line);
        return /* () */0;
      }));

exports.port = port;
exports.readline = readline;
/* port Not a pure module */
