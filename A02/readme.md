Create the patch file from linux-v6.1-rc3

#Create a branch from v6.1-rc3 tag
	`git checkout -b 6.1-rc3 tags/v6.1-rc3`
	`git push --set-upstream origin 6.1-rc3`

#Then, create the branch where the patch will be created

	`git checkout -t -b 6.1-rc3-thor_kernel 6.1-rc3`
	`Perform your edits & commits`

#Create the patch:

	`git format-patch --base=auto --cover-letter -o outgoing/ 6.1-rc3`
