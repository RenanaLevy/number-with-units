<div dir="rtl" lang="he">

# מספר עם יחידות


בשנת 1999, לוויין של נאס"א בשווי של 125 מיליון דולר התרסק בגלל אי-התאמה ביחידות - אחד הצוותים שפיתחו את הלוויין עבד ביחידות מטריות והצוות השני עבד ביחידות בריטיות (ראו דוגמאות נוספות 
[כאן](http://mentalfloss.com/article/25845/quick-6-six-unit-conversion-disasters)).

כדי שזה לא יקרה שוב, הם שכרו אתכם וביקשו מכם לכתוב מחלקה המייצגת מספר עם יחידות. במחלקה הזאת אפשר, למשל, לייצג את המספר "3 מטר" ואת המספר "40 סנטימטר", והסכום שלהם לא יהיה 43 אלא 3.4 מטר - המחלקה תדאג לבצע את ההמרה המתאימה. בנוסף, המחלקה לא תאפשר לחבר מספרים עם מימדים לא תואמים, למשל, חיבור של "3 מטר" עם "5 שניות" יגרום לזריקת חריגה.

הגדירו מחלקה בשם `NumberWithUnits` עם הפעולות הבאות (ראו בקובץ המצורף [Demo.cpp](Demo.cpp)):

* פונקציה בשם `read_units`, הקוראת את היחידות מתוך קובץ טקסט. קובץ טקסט לדוגמה נמצא [כאן](units.txt). 
* שישה אופרטורים חשבוניים: חיבור (+) הוספה (+=) פלוס אונרי (+), ושלושת האופרטורים המקבילים לחיסור (-). כאמור, חיבור של שני מספרים מאותו מימד יתבצע תוך המרת היחידה של המספר השני ליחידה של המספר הראשון; חיבור של שני מספרים ממימדים שונים יגרום לחריגה.
* שישה אופרטורי השוואה: גדול, גדול-או-שווה, קטן, קטן-או-שווה, שווה, לא-שווה, לפי אותם כללים של האופרטורים החשבוניים.
* הגדלה ב-1 (++) והקטנה ב-1 (--) לפני ואחרי המספר.
* הכפלה במספר ממשי (`double`). שימו לב: אין צורך לממש הכפלה של שני עצמים מסוג `NumberWithUnits`,
אלא רק `NumberWithUnits` כפול `double`. ההכפלה לא משנה את היחידות.
* אופרטור קלט ואופרטור פלט.

הערות לגבי קובץ המרת היחידות:

* אין חשיבות לרווח-לבן (אפשר לדלג על רווחים).
* הקובץ כולל מספר פקודות של המרת-יחידות. כל פקודה מתחילה ב"1", אחריה שם של יחידה, אחריה סימן "=", אחריה מספר כלשהו, ואחריה שם של יחידה אחרת. ראו דוגמה בקובץ [units.txt](units.txt).
* יחידות שאינן נמצאות בקובץ-היחידות נחשבות לא חוקיות: ניסיון לאתחל מספר עם יחידות כאלו יביא לזריקת חריגה.
* יחידות המוגדרות בקובץ-היחידות נחשבות חוקיות: אין צורך לבדוק שהנתונים בקובץ מתאימים למציאות.
* יש הבדל בין אותיות גדולות לקטנות. לדוגמה, אם בקובץ מוגדר "km" אז רק "km" נחשב חוקי - לא "KM" או "Km".

הערות לגבי קלט ופלט:

* פורמט הפלט של מספר עם יחידות הוא: המספר, אחריו (בלי רווח) סוגריים מרובעים, ובתוכן היחידות. ראו דוגמה בקובץ Demo.cpp.
* פורמט הקלט הוא דומה, פרט לכך שמותר שיהיו רווחים לבנים (מותר לדלג על רווחים בקריאה).
    
   

המימוש צריך לעבור את כל הבדיקות (60% מהציון):

<div dir='ltr'>

    make test1
    ./test1
    make test2
    ./test2
    make test3
    ./test3

</div>

בנוסף, הקוד צריך לעבור בהצלחה את מבחן הקריאות (20% מהציון):

<div dir='ltr'>

    make tidy

</div>

ואת מבחן הזיכרון (20% מהציון):

<div dir='ltr'>

    make valgrind

</div>

בנוסף, יש לכתוב **תוכנית ראשית** כלשהי המדגימה את הפתרון שלכם.
תוכן התוכנית לבחירתכם - תהיו יצירתיים. התוכנית לא תיבדק אוטומטית אלא רק בהצגה.

תוכלו לבדוק את הציון שלכם ע"י הפקודה:

<div dir='ltr'>

    bash grade

</div>

</div>
