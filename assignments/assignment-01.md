# Assignment 1 — Learn GitHub and Create Your Course Repository

**Course:** CSCI 272 — Object-Oriented Programming in C++<br>
**Instructor:** Avijit Roy<br>
**Term:** Fall 2026<br>
**Work:** Individual<br>
**Due:** See Brightspace<br>
**Submit:** Your GitHub repository link through the Assignment 1 submission area in Brightspace

## What You Will Accomplish

By the end of this assignment, you will have a public GitHub repository for your CSCI 272 practice work. You will use it to organize a Week 1 folder, upload your first C++ source file, record your work with commits, and submit the repository link for a grade.

You will learn how to:

- explain the purpose of a repository, README file, folder, and commit;
- create and organize a public GitHub repository;
- upload a C++ source file without uploading compiled or private files;
- use short, meaningful commit messages; and
- verify and submit a working repository link.

## Before You Begin

This assignment uses the GitHub website, so you do not need to install Git yet.

Use the [Git and GitHub Guide](https://avijitroy.com/docs/git/) as your step-by-step learning resource. Also keep the [Fall 2026 CSCI 272 syllabus](https://avijitroy.com/teaching/courses/csci272-fa26/) available for course policies and expectations.

> [!IMPORTANT]
> For Assignment 1, your course practice repository must be **Public**. This instruction applies to the practice repository created below. Later graded programming assignments may require a private repository or a Brightspace file submission; always follow the submission instructions for that assignment.

Keep this vocabulary nearby:

| Term | Meaning |
| --- | --- |
| Repository | A project space that stores files and their history |
| README | A Markdown file that explains the purpose and contents of a project or folder |
| Commit | A saved checkpoint with a message describing what changed |
| Source file | A human-readable program file, such as a C++ `.cpp` file |

> **Privacy and safety:** Your repository will be public. Never place a password, access token, CUNYfirst EMPLID, home address, phone number, private class material, graded assignment solution, or another student's work in it. Use a password that you do not use for another account. If you have a privacy or access concern about creating a public repository, contact Professor Roy before the deadline for an alternative arrangement.

## Learn

1. Open the [Git and GitHub Guide](https://avijitroy.com/docs/git/).
2. Read the introductory explanations of Git, GitHub, repositories, README files, and commits.
3. As you read, be ready to answer these questions in your own words:
   - What is a repository?
   - What information belongs in a README file?
   - What does a commit record?

You will apply each idea below. Do not only read the guide—complete every required action in your own GitHub account.

## Do

### 1. Create or Sign In to a GitHub Account

1. Go to [GitHub](https://github.com/).
2. Sign in, or select **Sign up** if you do not yet have an account.
3. If you create an account, verify the email address connected to it.
4. Choose a professional username that you will be comfortable sharing with your instructor and displaying publicly.

You are responsible for remembering your sign-in information. Do not submit your GitHub password to Brightspace or share it with anyone.

### 2. Create Your CSCI 272 Repository

1. From GitHub, select **New repository**. You may also select the **+** menu in the upper-right corner and then **New repository**.
2. Use this exact repository name:

   ```text
   CSCI-272-Fall-2026
   ```

3. Use this description:

   ```text
   C++ practice work for CSCI 272: Object-Oriented Programming in C++
   ```

4. Select **Public** so that the instructor can open the submitted link.
5. Select **Add a README file**.
6. Select **Create repository**.

This is a public practice repository. Do not use it to publish current graded programming solutions unless a later assignment explicitly allows you to do so.

### 3. Update the Repository README

1. Open the `README.md` file at the top level of your repository.
2. Select the pencil icon to edit it.
3. Replace the placeholder text with the following:

   ```markdown
   # CSCI 272 — Object-Oriented Programming in C++

   This repository contains my C++ practice work for CSCI 272, Fall 2026.

   ## Organization

   Practice files are organized by week. Each weekly folder includes a short README explaining its contents.
   ```

4. Commit the change with this message:

   ```text
   update course README
   ```

### 4. Create the Week 1 Folder and Reflection

1. Select **Add file**, then **Create new file**.
2. In the filename box, enter:

   ```text
   Week-01/README.md
   ```

   Entering the `/` creates the `Week-01` folder.

3. Add this heading and answer each prompt in your own words:

   ```markdown
   # Week 1

   This folder contains my Week 1 C++ practice work.

   ## What I learned

   - A repository is ...
   - A README file helps ...
   - A commit records ...
   - One question I still have is ...
   ```

4. Commit the file with this message:

   ```text
   add Week 1 README and reflection
   ```

### 5. Add Your First C++ Source File

1. Compile and run the first C++ practice program you created in class.
2. Save the source file with a clear name ending in `.cpp`.
3. In GitHub, open the `Week-01` folder and select **Add file**, then **Upload files**.
4. Upload the `.cpp` source file.
5. Commit it with this message:

   ```text
   add first C++ practice program
   ```

If you have not yet created a class practice file, create a small `hello.cpp` program that prints `Hello, CSCI 272!`, compile and run it, and then upload the source file.

Upload the `.cpp` source file only. Do **not** upload `.exe` files, IDE build folders, passwords, tokens, private course files, or unrelated personal files.

### 6. Check Your Finished Repository

Before submitting, confirm that your repository contains:

```text
CSCI-272-Fall-2026/
├── README.md
└── Week-01/
    ├── README.md
    └── your-program.cpp
```

Also confirm that:

- the repository name is exactly `CSCI-272-Fall-2026`;
- the repository visibility is **Public**;
- both README files display correctly;
- the Week 1 README answers all four reflection prompts;
- the `.cpp` file opens and shows your source code;
- your commit history contains meaningful messages; and
- the repository contains no private information or prohibited files.

Copy the repository URL from your browser. It should follow this pattern:

```text
https://github.com/YourUsername/CSCI-272-Fall-2026
```

Open the URL in a private or incognito browser window. If you can view the repository while signed out, the instructor can view it for grading.

## Submit for a Grade

1. Open the **Assignment 1** submission area in Brightspace.
2. Paste the full URL of your `CSCI-272-Fall-2026` repository into the submission text box or comments field.
3. Select the final **Submit** button.
4. Reopen your submission and confirm that the URL is correct and clickable.
5. Keep the Brightspace submission confirmation for your records.

Do not submit your GitHub username by itself, a password, a link to the GitHub home page, or a link that the instructor cannot open. Brightspace is the official location for the deadline, submission record, feedback, and grade.

## Academic Work and AI Use

Write the Week 1 reflection in your own words. Do not copy another student's README or source file.

If you use an AI tool for permitted help, add a short disclosure to `Week-01/README.md` that identifies the tool, date, prompt, and how the response helped you. Keep the conversation history, and be prepared to explain every file you submit. Never paste passwords, tokens, personal information, or private course material into an AI tool.

## Grading — 100 Points

| Requirement | Points |
| --- | ---: |
| Repository has the exact name, description, public visibility, and an accessible link | 20 |
| Top-level `README.md` correctly identifies and explains the course repository | 15 |
| `Week-01/README.md` is in the correct folder and includes complete reflection answers | 20 |
| At least one valid `.cpp` source file is uploaded to `Week-01` | 20 |
| Commit history shows the required work with clear, meaningful messages | 15 |
| Correct repository URL is submitted successfully through Brightspace | 10 |
| **Total** | **100** |

A repository link that cannot be opened cannot receive credit for items the instructor cannot verify. If a technical or account-access problem may prevent submission, contact Professor Roy before the deadline and include a screenshot of the problem—never include a password or access token.

## Final Reminder

The goal is not merely to own a GitHub account. The goal is to practice a professional habit:

**learn the tool → organize your work → save meaningful checkpoints → verify the result → submit it correctly**

---

*Git and GitHub learning resource and assignment developed by Professor Avijit Roy for CSCI 272.*
