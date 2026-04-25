# Debugging C in VSCode - Quick Guide

## Setup (Already Done!)
✅ `launch.json` configured with two debug targets  
✅ `tasks.json` set up to build debug versions  

## How to Debug Your Code

### Step 1: Set Breakpoints
Click in the **left margin** of any `.c` file next to a line number. A red dot will appear.

Example: Click next to the `create(&board)` line in test_board.c to pause execution there.

### Step 2: Start Debugging

**Option A: Debug Tests**
1. Go to **Run → Start Debugging** (or press `F5`)
2. Select **"Debug Tests (GDB)"**
3. Code will build and run, stopping at your first breakpoint

**Option B: Debug Main Program**
1. Go to **Run → Start Debugging** (or press `F5`)
2. Select **"Debug Main Program (GDB)"**
3. Code will build and start the main tictactoe program

### Step 3: Navigate Execution

Once paused at a breakpoint, use these controls (top toolbar):

- **Continue** (▶) or `F5` - Run until next breakpoint
- **Step Over** (⤵) or `F10` - Execute current line, stay at same level
- **Step Into** (↙) or `F11` - Enter function calls
- **Step Out** (⤴) or `Shift+F11` - Exit current function

### Step 4: Inspect Variables

When paused, you can:
- **Hover over variables** to see their value
- **Watch panel** (left sidebar) - Add specific variables to monitor
- **Debug Console** (bottom) - Type commands like:
  ```
  p board         (print variable)
  p board[0]      (print array element)
  p *board        (dereference pointer)
  ```

### Step 5: Find Your Bug

The bug is in `test_board.c` line ~49 in the `test_board_parse()` function.

**Debug it:**
1. Set a breakpoint at line 50
2. Start debugging tests
3. When it hits the breakpoint, look at the variables
4. Step through the code and watch what happens
5. Check the error/crash to understand what went wrong

---

## Common Debugging Scenarios

### Segmentation Fault
- Usually means accessing invalid memory (null pointer, wrong address)
- Look at what pointer operations happen before the crash
- Check pointer initialization and dereferences

### Variable Has Wrong Value
- Step through code line-by-line
- Check variable assignments
- Verify function parameters are passed correctly

### Understanding Pointer/Array Issues
- Use the Watch panel to monitor pointer values
- Print array contents: `p board[0]`, `p board[1]`, etc.
- Check memory addresses: `&variable`

---

## Your Current Bug

There's a compilation/runtime error in `test_board.c`. Use the debugger to:

1. **Set breakpoint** at line 50 (or wherever test_board_parse starts)
2. **Step into** create() to see what's happening
3. **Check the board pointer** - is it valid?
4. **Compare with test_board()** - what's different?

---

## Keyboard Shortcuts Summary

| Action | Windows/Linux | Mac |
|--------|---------------|-----|
| Start Debug | F5 | F5 |
| Continue | F5 | F5 |
| Step Over | F10 | F10 |
| Step Into | F11 | F11 |
| Step Out | Shift+F11 | Shift+F11 |
| Toggle Breakpoint | F9 | F9 |

---

## Tips

- **Conditional Breakpoints**: Right-click breakpoint → "Edit Breakpoint" → add condition like `i == 50`
- **Debug Console**: Type `-exec gdb_command` to run raw GDB commands
- **Logpoints**: Right-click → "Add Logpoint" to print messages without stopping
- **Restart**: Press the Restart button (⟲) instead of stopping/starting

Happy debugging! 🐛
