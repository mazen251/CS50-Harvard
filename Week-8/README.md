# Week 8: HTML, CSS, and JS

## Overview

HTML and CSS are markup languages, while JavaScript (JS) is a programming language commonly used to make interfaces interactive in browsers, though it can also be used server-side.

## Networking Basics

### Packets

Packets are like envelopes that contain information sent through the mail, with routers acting as mailmen who deliver them.

### TCP/IP

The internet uses two primary protocols to send messages from A to B:
- **IP (Internet Protocol)**: Provides a unique address for each computer. IPv4 addresses are in the format #.#.#.# (4 bytes = 32 bits), allowing for 4 billion unique addresses. IPv6, which uses 128 bits, is gradually being adopted.
- **TCP (Transmission Control Protocol)**: Ensures reliable delivery by adding a sequence number to packets and using port numbers to identify the type of message (e.g., port 80 for HTTP, port 443 for HTTPS).

## DNS (Domain Name System)

The DNS server answers questions about domain names and their corresponding IP addresses. It functions like a dictionary or hash table with a hierarchical design. If a DNS server doesn’t know an answer, it queries higher-level servers until it reaches the ROOT servers.

## DHCP (Dynamic Host Configuration Protocol)

DHCP answers questions about which DNS server and router your device should use when connecting to a network.

## HTTP (Hypertext Transfer Protocol)

HTTP governs how web browsers and servers communicate. HTTP requests and responses involve clients requesting information and servers providing it. HTTPS is the secure version of HTTP with encryption.

### HTTP Methods

- **GET**: Requests information from a server (e.g., retrieving data).
- **POST**: Sends information to a server (e.g., uploading data).

We'll focus on GET.

## HTML Basics

HTML is structured with tags and attributes. Here’s a basic example:
```html
<!DOCTYPE html> <!-- Document type declaration (latest version) -->
<!-- Demonstrates HTML -->
<html lang="en">
    <head>
        <title>Hello, Title</title>
    </head>
    <body>
        Hello, Body
    </body>
</html>
```

- `<html>`: Start tag for HTML.
- `</html>`: End tag for HTML.
- Elements: Anything inside start and end tags (e.g., `<head>`, `<body>`).



### Important Tags

- `<p>`: Paragraph tag
- `<div>`: General container tag
- `<h1>` to `<h6>`: Heading tags
- `<ul>`: Unordered list tag with `<li>` items
- `<ol>`: Ordered list with `<li>` items
- `<table>`, `<tr>`, `<td>`: Table tags (table, row, cell)
- `<img>`: Image tag with src attribute for image source and alt for alternative text
- `<video>`: Video tag with attributes like controls and muted, and `<source>` for specifying video type

- **Example:**
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <title>Video</title>
    </head>
    <body>
        <video controls muted>
            <source src="video.mp4" type="video/mp4">
        </video>
    </body>
</html>
```


### Linking
```html
To link web pages, use the anchor tag <a> with the href attribute:
<body>
    Visit <a href="https://www.harvard.edu">Harvard</a>.
</body>
```


### Meta Tags

Used for metadata and mobile optimization. For example, meta tags for character set and viewport settings.



### Forms

- **To create forms:**
```html
<!DOCTYPE html>
<!-- Demonstrates form -->
<html lang="en">
    <head>
        <title>Search</title>
    </head>
    <body>
        <form action="https://www.google.com/search" method="get">
            <input name="q" type="search">
            <input type="submit" value="Google Search">
        </form>
    </body>
</html>
```
- **Improved form:**
```html
<!DOCTYPE html>
<!-- Demonstrates additional form attributes -->
<html lang="en">
    <head>
        <title>Search</title>
    </head>
    <body>
        <form action="https://www.google.com/search" method="get">
            <input autocomplete="off" autofocus name="q" placeholder="Query" type="search">
            <button>Google Search</button>
        </form>
    </body>
</html>
```

### Regular Expressions (Regex)

Used to validate or extract information from strings. For example, to validate an email address:
```html
<!DOCTYPE html>
<!-- Demonstrates pattern attribute -->
<html lang="en">
    <head>
        <title>Register</title>
    </head>
    <body>
        <form>
            <input autocomplete="off" autofocus name="email" pattern=".+@.+\.edu" placeholder="Email" type="email">
            <button>Register</button>
        </form>
    </body>
</html>
```


## CSS (Cascading Style Sheets)

Uses key-value pairs called properties. You can include CSS directly in HTML or link to an external CSS file.

- **Example of inline CSS:**
```html
<!DOCTYPE html>
<!-- Demonstrates inline CSS with P tags -->
<html lang="en">
    <head>
        <title>CSS</title>
    </head>
    <body>
        <p style="font-size: large; text-align: center;">
            John Harvard
        </p>
        <p style="font-size: medium; text-align: center;">
            Welcome to my home page!
        </p>
        <p style="font-size: small; text-align: center;">
            Copyright &#169; John Harvard
        </p>
    </body>
</html>
```
- **Improved version using <div> and a CSS file:**
```html
<!DOCTYPE html>
<!-- Removes outer DIV -->
<html lang="en">
    <head>
        <title>CSS</title>
    </head>
    <body style="text-align: center">
        <div style="font-size: large">
            John Harvard
        </div>
        <div style="font-size: medium">
            Welcome to my home page!
        </div>
        <div style="font-size: small">
            Copyright &#169; John Harvard
        </div>
    </body>
</html>
```
- **You can further improve by using an external CSS file:**
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <title>CSS</title>
        <link href="style.css" rel="stylesheet">
    </head>
    <body>
        <div class="large-text">John Harvard</div>
        <div class="medium-text">Welcome to my home page!</div>
        <div class="small-text">Copyright &#169; John Harvard</div>
    </body>
</html>
```
```css
style.css:
body {
    text-align: center;
}
.large-text {
    font-size: large;
}
.medium-text {
    font-size: medium;
}
.small-text {
    font-size: small;
}
```


## JS (JavaScript)

JavaScript is used to create interactive elements on web pages. Examples include form validation, dynamic content updates, and handling user events. (for further notes, seek the cs50 week-8 lecture notes & slides on edx)
