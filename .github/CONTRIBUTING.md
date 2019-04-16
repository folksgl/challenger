## How to contribute to Challenger

#### **Setting up a development environment**
* First things first, clone the Challenger repository or branch you wish to work on.
* Make sure you can compile the project. For most linux systems, running 'cmake -H. -Bbuild' will do the trick. Challenger uses cmake to generate its makefiles so feel free to set the build directory wherever you choose.
* **The most important step by far** is to understand the code that is already in place. Attempting to develop and add new features without understanding the codebase will likely result in adding code that will only introduce bugs to your development branch.

A propperly set up development environment will be able to do the following **without error or warning**:
  - [x] make
  - [x] make test
  - [x] make clean

Note: cmake includes the googletest framework into the project during its generation stage. You do not have to have googletest already installed on your system. This is done to keep all branches as homogenous as possible and speed up the development process.

#### **Is there an optimization you would like to introduce to challenger?**

* **Create a branch** and optimize away! We're still working out a way to benchmark challenger so stay tuned on how to prove your optimization works. For now, demonstrating an improvment in the current level of stockfish beaten would be more than enough.

#### **Did you find a bug?**

* **Ensure the bug was not already reported** by searching on GitHub under [Issues](https://github.com/folksgl/challenger/issues).

* If you're unable to find an open issue addressing the problem, [open a new one](https://github.com/folksgl/challenger/issues/new). Be sure to include a **title and clear description**, as much relevant information as possible, and a **code sample** or an **executable test case** demonstrating the expected behavior that is not occurring.

#### **Did you write a patch that fixes a bug?**

* Open a new GitHub pull request with the patch by heading to the [pull request page](https://github.com/folksgl/challenger/pulls).

* Ensure the PR description clearly describes the problem and solution. Include the relevant issue number if applicable.

#### **Do you intend to add a new feature or change an existing one?**

* Open a new GitHub pull request on the [pull request page](https://github.com/folksgl/challenger/pulls). Make sure to write and submit the relevant tests for your code as this will help speed the request along.
