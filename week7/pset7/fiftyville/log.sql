-- Keep a log of any SQL queries you execute as you solve the mystery.


SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = "Chamberlin Street";

-- Select name and interviews where courthouse in mentioned 
SELECT name,transcript FROM interviews WHERE year = 2020 AND month = 7 AND day = 28 AND transcript LIKE "%courthouse%";

-- Get list of license Plates of culprit/accomplice
SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND activity = "exit" AND minute BETWEEN 15 AND 25;

-- Get list of bank account numbers of culprit
SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw";

-- Get list of person_id for list of bank account numbers of culprit
SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw");

-- Get list of Culprit & accomplice phone numbers
SELECT caller, receiver FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60;

-- Get id of flight, destination aiprort id of location where they escaped to
SELECT id,destination_airport_id FROM flights WHERE hour =(SELECT min(hour) FROM flights WHERE day = 29 AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville")) AND day = 29;

-- ANS 2 : Get location of where they escaped to based on destination_airport_id
SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE hour = (SELECT min(hour) FROM flights WHERE day = 29 AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville")) AND day = 29);

-- get list of passport numbers of culprit & accomplice
SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE hour = (SELECT min(hour) FROM flights WHERE day = 29 AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville")) AND day = 29);

-- Get name of Culprit
SELECT name 
FROM people 
WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60)
AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE hour = (SELECT min(hour) FROM flights WHERE day = 29 AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville")) AND day = 29))
AND license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND activity = "exit" AND minute BETWEEN 15 AND 25)
AND id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw"))
;

-- Get name of Accomplice // Accomplice DID NOT take the flight
SELECT name 
FROM people 
WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60 AND caller = (SELECT phone_number FROM people WHERE name = "Ernest"))
;
