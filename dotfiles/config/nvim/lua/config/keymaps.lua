-- Keymaps are automatically loaded on the VeryLazy event
-- Default keymaps that are always set: https://github.com/LazyVim/LazyVim/blob/main/lua/lazyvim/config/keymaps.lua
-- Add any additional keymaps here

local map = vim.keymap.set

--------------------------------------
-- Custom Mappings
--------------------------------------

-- Move selected line / block of text in visual mode
map("v", "J", ":m '>+1<CR>gv=gv", { desc = "Move line down" })
map("v", "K", ":m '<-2<CR>gv=gv", { desc = "Move line up" })

-- Preserve Cursor on Join
map("n", "J", "mzJ`z", { desc = "join lines and preserve cursor" })

-- Keep Cursors centered on certain actions
map("n", "n", "nzzzv", { desc = "Move to next search item and center" })
map("n", "N", "Nzzzv", { desc = "Move to previous search item and center" })
map("n", "<C-d>", "<C-d>zz", { desc = "Move half page down and center" })
map("n", "<C-u>", "<C-u>zz", { desc = "Move half page up and center" })

-- yank, paste and clipboard
map({ "n", "v" }, "<leader>y", '"+y', { desc = "Copy to clipboard" })
map({ "n", "v" }, "<leader>p", '"+p', { desc = "Paste from clipboard" })
map("n", "<leader>Y", '"+Y', { desc = "Copy line to clipboard" })
map("v", "p", '"_dP', { desc = "Paste over into void" })

-- delete to void
map({ "v", "n" }, "<leader>dc", '"_d', { desc = "Delete to void" })
map("n", "<leader>dd", '"_dd', { desc = "Delete line to void" })

-- use H an L to go to start or end of line
map("n", "H", "^", { desc = "Goto Beginning of Line" })
map("n", "L", "$", { desc = "Goto End of Line" })

---------------------------------------
-- Plugin Mappings
---------------------------------------

map("i", "<C-g>", function()
  vim.fn.feedkeys(vim.fn["copilot#Accept"](), "")
end, { desc = "Copilot Accept", silent = true })

map("n", "<leader>qf", function()
  vim.lsb.buf.code_action({
    filter = function(a)
      return a.isPreferred
    end,
    apply = true,
  })
end, { desc = "LSP: Apply preferred fix", silent = true })

map("n", "<leader>so", "<cmd>LspClangdSwitchSourceHeader<cr>", {
  desc = "Switch Source/Header",
})
