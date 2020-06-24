// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Three = require("three");

function ensureT(v) {
  if (v.tag) {
    return v[0];
  } else {
    return new Three.Vector2(v[0], v[1]);
  }
}

function ensureTClone(v) {
  if (v.tag) {
    return v[0].clone();
  } else {
    return new Three.Vector2(v[0], v[1]);
  }
}

function add(v1, v2) {
  return /* Three */Block.__(1, [ensureT(v1).add(ensureT(v2))]);
}

function normalize(v) {
  return /* Three */Block.__(1, [ensureT(v).normalize()]);
}

function length(v) {
  return ensureT(v).length();
}

function multiplyScalar(m, v) {
  return /* Three */Block.__(1, [ensureT(v).multiplyScalar(m)]);
}

var Vector2 = {
  ensureT: ensureT,
  ensureTClone: ensureTClone,
  add: add,
  normalize: normalize,
  length: length,
  multiplyScalar: multiplyScalar
};

exports.Vector2 = Vector2;
/* three Not a pure module */
