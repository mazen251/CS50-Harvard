**Week 9: Flask**

**Introduction**

- Flask: A micro web framework for Python that allows you to build web applications quickly. It is smaller and simpler compared to other frameworks.

**Setup**

- Install Flask using pip: `pip install Flask`
- Basic Structure: Create a `hello.py` file to start a simple Flask app.

**Routing**

- **Routes**: Define URLs that map to functions.
  - Example:
```python  
    @app.route('/')
    def index():
        return 'Hello, World!'
```
- **Dynamic URLs**: Use `<variable>` syntax to capture values from the URL.
  - Example:
```python  
    @app.route('/user/<username>')
    def profile(username):
        return f'User: {username}'
```
**Templates**

- **Jinja2**: Templating engine used by Flask to render HTML with dynamic content.
- **Templates Folder**: Store HTML files in the `templates` directory.
- **Rendering**: Use `render_template` to render a template with variables.
  - Example:
```python  
    from flask import render_template
    
    @app.route('/greet/<name>')
    def greet(name):
        return render_template('greet.html', name=name)
```
**Forms**

- **Form Handling**: Use `request` object to access form data.
  - Example:
```python
from flask import request

@app.route('/submit', methods=['POST'])
def submit():
    name = request.form['name']
    return f'Hello, {name}!'
```
**Databases**

- Use SQL for database interactions (refer to Week 7 for details).

**Authentication**

- **Sessions**: Use Flask's session management to handle user logins and keep track of user sessions (note: not always secure).
  - Example:
```python  
from flask import session, redirect

@app.route('/login', methods=['POST'])
def login():
    session['user_id'] = user_id
    return redirect('/')
```
**Deployment**

- Multiple options available such as Heroku, AWS, Azure, etc.
