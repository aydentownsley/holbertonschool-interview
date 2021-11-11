#!/usr/bin/node
const request = require('request');
const movieId = process.argv[2].toString();
const url = 'https://swapi-api.hbtn.io/api/films/' + movieId;

request(url, function (err, res, body) {
  if (err) {
    console.log(err);
  }
  const charUrlList = JSON.parse(body).characters;
  const char = {};

  charUrlList.forEach(character => {
    request(character, function (err, res, body) {
      if (err) {
        console.log(err);
      }
      const charName = JSON.parse(body).name;
      char[character] = charName;
      if (Object.values(char).length === charUrlList.length) {
        charUrlList.forEach(character => {
          console.log(char[character]);
        });
      }
    });
  });
});
