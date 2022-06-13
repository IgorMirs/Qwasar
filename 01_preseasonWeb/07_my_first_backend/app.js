const express = require('express')
const app = express()
const port = 8080
songs = ["Accidents Will Happen", "Adeste Fideles", "Ad-Lib Blues", 
         "An Affair to Remember (Our Love Affair)", "After You've Gone", 
         "Ain't She Sweet", "Ain't Cha Ever Comin' Back?", 
         "Air For English Horn", "Alice Blue Gown", "All Alone", 
         "All By Myself", "All I Do Is Dream of You", "All I Need is the Girl",
         "All My Tomorrows", "All of Me", "All of You", "All or Nothing at All",
         "All Through the Day", "America the Beautiful", "Among My Souvenirs",
         "And Then You Kissed Me"]

app.get('/', (req, res) => {
    res.send(songs[Math.floor(Math.random() * songs.length)])
})

app.get('/birth_date', (req, res) => {
    res.send("12/05/1915")
})

app.get('/birth_city', (req, res) => {
    res.send("Hoboken, New Jersey")
})

app.get('/wives', (req, res) => {
    res.send("Nancy Sinatra, Ava Gardner, Mia Farrow, Barbara Sinatra")
})

app.listen(port, '0.0.0.0', () => {
        console.log('Example app listening on port ' + port)
    })