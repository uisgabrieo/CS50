-- Keep a log of any SQL queries you execute as you solve the mystery.

-- View the first 5 crime scene reports to understand the table structure
SELECT * FROM crime_scene_reports
LIMIT 5;

-- View crimes that occurred on 07/28/2023 on Humphrey Street
SELECT * FROM crime_scene_reports
WHERE day = 28
AND month = 7
AND year = 2023
AND street = "Humphrey Street";

-- Reports from interviewees mentioning the bakery
SELECT transcript FROM interviews
WHERE day = 28
AND month = 7
AND year = 2023
AND transcript LIKE "%bakery%";

-- Cars that exited the location within a 10-minute window
SELECT * FROM bakery_security_logs
WHERE day = 28
AND month = 7
AND year = 2023
AND hour = 10
AND minute >= 15 AND minute <= 25
AND activity = "exit";

-- Withdrawals made on 07/28/2023 at the Leggett Street ATM
SELECT * FROM atm_transactions
WHERE day = 28
AND month = 7
AND year = 2023
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw";

-- Phone calls lasting less than 1 minute
SELECT * FROM phone_calls
WHERE day = 28
AND month = 7
AND year = 2023
AND duration < 60;

-- Flights scheduled for 07/29/2023 in descending order
SELECT * FROM flights
WHERE day = 29
AND month = 7
AND year = 2023
ORDER BY hour DESC;

-- All passengers on flight 36
SELECT * FROM passengers
WHERE flight_id = 36;

-- Names of people who were on flight 36 and made a phone call on 07/28/2023 lasting less than 1 minute
SELECT DISTINCT name FROM people AS p
JOIN passengers AS ps ON p.passport_number = ps.passport_number
JOIN phone_calls AS pc ON p.phone_number = pc.caller
WHERE flight_id = 36
AND pc.day = 28
AND pc.month = 7
AND pc.year = 2023
AND pc.duration < 60;

-- People who exited the bakery between 10:15 and 10:25
SELECT DISTINCT name FROM people AS p
JOIN passengers AS ps ON p.passport_number = ps.passport_number
JOIN phone_calls AS pc ON p.phone_number = pc.caller
JOIN bakery_security_logs AS bs ON p.license_plate = bs.license_plate
WHERE flight_id = 36
AND pc.day = 28
AND pc.month = 7
AND pc.year = 2023
AND pc.duration < 60
AND bs.hour = 10
AND bs.minute >= 15 AND bs.minute <= 25;

-- Person who withdrew money on 07/28/2023
-- Bruce GUILTY
SELECT DISTINCT name FROM people AS p
JOIN passengers AS ps ON p.passport_number = ps.passport_number
JOIN phone_calls AS pc ON p.phone_number = pc.caller
JOIN bakery_security_logs AS bs ON p.license_plate = bs.license_plate
JOIN bank_accounts AS ba ON ba.person_id = p.id
WHERE flight_id = 36
AND pc.day = 28
AND pc.month = 7
AND pc.year = 2023
AND pc.duration < 60
AND bs.hour = 10
AND bs.minute >= 15 AND bs.minute <= 25;

-- Bruce's data
SELECT * FROM people
WHERE name = "Bruce";

-- All phone calls made by Bruce on 07/28/2023 lasting less than 1 minute
SELECT * FROM phone_calls
WHERE day = 28
AND month = 7
AND year = 2023
AND duration < 60
AND caller = "(367) 555-5533";

-- Person who received Bruce's call on 07/28/2023 lasting less than 1 minute
-- Robin ACCOMPLICE
SELECT * FROM people
WHERE phone_number = "(375) 555-8161";

-- Destination of Bruce's flight on 07/29/2023, flight 36
SELECT destination_airport_id FROM flights
WHERE day = 29
AND month = 7
AND year = 2023
AND id = 36;

-- Location of the airport where Bruce attempted to escape
-- New York City
SELECT city FROM airports
WHERE id = 4;
